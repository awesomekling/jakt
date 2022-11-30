
cmake_minimum_required(VERSION 3.16..3.21)
cmake_policy(SET CMP0091 NEW)

project(Jakt
        VERSION 0.0.1
        LANGUAGES CXX
        HOMEPAGE_URL https://github.com/SerenityOS/jakt
        DESCRIPTION "Jakt programming language compiler")

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}" CACHE FILEPATH "Path to a compiler launcher program, e.g. ccache")
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}" CACHE FILEPATH "Path to a compiler launcher program, e.g. ccache")
endif()

include(GNUInstallDirs)

include_directories(/home/kling/src/serenity)
add_compile_options(-DUSING_AK_GLOBALLY=0)

set(NO_SYMLINKS_DEFAULT OFF)
if (CMAKE_HOST_WIN32)
  set(NO_SYMLINKS_DEFAULT ON)
endif()

set(FINAL_STAGE "1" CACHE STRING "Compiler stage to stop at, either 1 (default) or 2)")
option(NO_SYMLINKS "Use hard links instead of symlinks. Useful for unprivileged Windows users" "${NO_SYMLINKS_DEFAULT}")

if (NO_SYMLINKS)
  set(LINK_COMMAND create_hardlink)
  set(LINK_GENEX TARGET_FILE)
else()
  set(LINK_COMMAND create_symlink)
  set(LINK_GENEX TARGET_FILE_NAME)
endif()

set(in_build_prefix "")
get_cmake_property(is_multi_config GENERATOR_IS_MULTI_CONFIG)
if (is_multi_config)
  set(in_build_prefix "$<CONFIG>/")
endif()

function(apply_output_rules target)
  set_property(TARGET ${target} PROPERTY "ARCHIVE_OUTPUT_DIRECTORY" "${CMAKE_BINARY_DIR}/${in_build_prefix}lib")
  set_property(TARGET ${target} PROPERTY "LIBRARY_OUTPUT_DIRECTORY" "${CMAKE_BINARY_DIR}/${in_build_prefix}lib")
  set_property(TARGET ${target} PROPERTY "RUNTIME_OUTPUT_DIRECTORY" "${CMAKE_BINARY_DIR}/${in_build_prefix}bin")
endfunction()

include(cmake/jakt-executable.cmake)

add_subdirectory(runtime)

file(GLOB JAKT_STAGE0_SOURCES CONFIGURE_DEPENDS "bootstrap/stage0/*.cpp")
add_executable(jakt_stage0 "${JAKT_STAGE0_SOURCES}")
add_executable(Jakt::jakt_stage0 ALIAS jakt_stage0)
add_jakt_compiler_flags(jakt_stage0)
target_include_directories(jakt_stage0
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/bootstrap/stage0/runtime>
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/bootstrap/stage0/runtime>
  PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/runtime>
)
target_link_libraries(jakt_stage0 PRIVATE Jakt::jakt_runtime Jakt::jakt_main)
apply_output_rules(jakt_stage0)

set(SELFHOST_SOURCES
  selfhost/build.jakt
  selfhost/codegen.jakt
  selfhost/compiler.jakt
  selfhost/error.jakt
  selfhost/formatter.jakt
  selfhost/ide.jakt
  selfhost/interpreter.jakt
  selfhost/lexer.jakt
  selfhost/parser.jakt
  selfhost/project.jakt
  selfhost/repl.jakt
  selfhost/typechecker.jakt
  selfhost/types.jakt
  selfhost/utility.jakt
  selfhost/os.jakt
  selfhost/path.jakt
)

if(CMAKE_HOST_WIN32)
  list(APPEND SELFHOST_SOURCES
    selfhost/windows_fs.jakt
    selfhost/windows_errno.jakt
    selfhost/windows_process.jakt
    selfhost/windows_compiler.jakt
  )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  list(APPEND SELFHOST_SOURCES
    selfhost/posix_fs.jakt
    selfhost/darwin_errno.jakt
    selfhost/posix_process.jakt
    selfhost/posix_compiler.jakt
  )
elseif(CMAKE_HOST_UNIX)
  list(APPEND SELFHOST_SOURCES
    selfhost/posix_fs.jakt
    selfhost/posix_errno.jakt
    selfhost/posix_process.jakt
    selfhost/posix_compiler.jakt
  )
else()
  list(APPEND SELFHOST_SOURCES
    selfhost/unknown_fs.jakt
    selfhost/unknown_process.jakt
    selfhost/unknown_compiler.jakt
  )
endif()

# FIXME: STDLIB target needed
set(SELFHOST_STDLIB_SOURCES
  jakt__libc__io.cpp
  jakt__arguments.cpp
  jakt__file_iterator.cpp
)

add_jakt_executable(jakt_stage1
  COMPILER jakt_stage0
  MAIN_SOURCE selfhost/main.jakt
  MODULE_SOURCES ${SELFHOST_SOURCES}
  STDLIB_SOURCES ${SELFHOST_STDLIB_SOURCES}
  RUNTIME_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/runtime"
)

target_include_directories(jakt_stage1
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/runtime>
  PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/runtime>
)
add_executable(Jakt::jakt_stage1 ALIAS jakt_stage1)
apply_output_rules(jakt_stage1)

if (FINAL_STAGE GREATER_EQUAL 2)
  add_jakt_executable(jakt_stage2
    COMPILER jakt_stage1
    MAIN_SOURCE selfhost/main.jakt
    MODULE_SOURCES ${SELFHOST_SOURCES}
    STDLIB_SOURCES ${SELFHOST_STDLIB_SOURCES}
    RUNTIME_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/runtime"
  )
  target_include_directories(jakt_stage2
    INTERFACE
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/runtime>
    PUBLIC
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/runtime>
  )
  add_executable(Jakt::jakt_stage2 ALIAS jakt_stage2)
  apply_output_rules(jakt_stage2)
endif()

# Link runtime into build directory(ies) for relative pathing usage
#    Note: "If a sequential execution of multiple commands is required, use multiple execute_process() calls with a single COMMAND argument."
if (CMAKE_CONFIGURATION_TYPES)
  foreach (build_type IN LISTS CMAKE_CONFIGURATION_TYPES)
    execute_process(COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/${build_type}/include")
    execute_process(COMMAND "${CMAKE_COMMAND}" -E ${LINK_COMMAND} "${CMAKE_CURRENT_SOURCE_DIR}/runtime" "${CMAKE_CURRENT_BINARY_DIR}/${build_type}/include/runtime")
  endforeach()
else()
  execute_process(COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/include")
  execute_process(COMMAND "${CMAKE_COMMAND}" -E ${LINK_COMMAND}  "${CMAKE_CURRENT_SOURCE_DIR}/runtime" "${CMAKE_CURRENT_BINARY_DIR}/include/runtime")
endif()

add_custom_command(
  TARGET "jakt_stage${FINAL_STAGE}"
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E ${LINK_COMMAND}  "$<${LINK_GENEX}:jakt_stage${FINAL_STAGE}>" "$<TARGET_FILE_DIR:jakt_stage${FINAL_STAGE}>/jakt${CMAKE_EXECUTABLE_SUFFIX}"
  VERBATIM
)
add_executable(Jakt::jakt ALIAS jakt_stage${FINAL_STAGE})

if (NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# FIXME: Remove if we decide to use CTest
option(JAKT_BUILD_TESTING "Whether to build tests or not, default on" ON)

if (JAKT_BUILD_TESTING)
  add_jakt_executable(jakttest
    MAIN_SOURCE
      jakttest/jakttest.jakt
    MODULE_SOURCES
      jakttest/error.jakt
      jakttest/lexer.jakt
      jakttest/parser.jakt
      jakttest/utility.jakt
    INCLUDES
      "${CMAKE_CURRENT_SOURCE_DIR}/jakttest"
  )
  add_jakt_compiler_flags(jakttest)
  target_sources(jakttest PRIVATE
     jakttest/fs.cpp
     jakttest/os.cpp
     jakttest/process.cpp
  )
  apply_output_rules(jakttest)
endif()
