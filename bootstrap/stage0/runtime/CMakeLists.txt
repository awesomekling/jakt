include(FetchContent)

FetchContent_Declare(Serenity
    GIT_REPOSITORY https://github.com/serenityos/serenity.git
    GIT_TAG origin/master
    GIT_SHALLOW TRUE
    SOURCE_DIR serenity
    EXCLUDE_FROM_ALL
)

if (SERENITY_SOURCE_DIR)
    set(FETCHCONTENT_SOURCE_DIR_SERENITY
        ${SERENITY_SOURCE_DIR}
        CACHE PATH
        "Developer's preexisting SerenityOS source directory" FORCE
    )
    message(STATUS
        "Using preexisting AK directory from SERENITY_SOURCE_DIR: ${SERENITY_SOURCE_DIR}/AK"
    )
endif()

FetchContent_GetProperties(Serenity)
if (NOT serenity_POPULATED)
    FetchContent_Populate(Serenity)
endif()

file(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/AK)
file(COPY ${serenity_SOURCE_DIR}/AK DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

configure_file("AK/Debug.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/AK/Debug.h")

set(JAKT_AK_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "jakt_ak_source_dir")

set(IMPORTED_AK_SOURCES
    ${JAKT_AK_SOURCE_DIR}/AK/Assertions.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Base64.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/DeprecatedFlyString.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/DeprecatedString.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/FloatingPointStringConversions.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/FlyString.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Format.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/FuzzyMatch.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/GenericLexer.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Hex.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/JsonParser.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/JsonPath.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/JsonValue.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/LexicalPath.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Random.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StackInfo.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/String.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StringBuilder.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StringFloatingPointConversions.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StringImpl.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StringUtils.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/StringView.cpp
    # Note: Does not build on windows right now, but not needed by the runtime anyway.
    # ${JAKT_AK_SOURCE_DIR}/AK/Time.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/URL.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/URLParser.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/UUID.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Utf16View.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/Utf8View.cpp
    ${JAKT_AK_SOURCE_DIR}/AK/kmalloc.cpp
)

set(RUNTIME_SOURCES
    ${IMPORTED_AK_SOURCES}
    IO/File.cpp
    Jakt/PrettyPrint.cpp
    Jakt/DeprecatedStringBuilder.cpp
)

add_library(jakt_runtime STATIC ${RUNTIME_SOURCES})
add_jakt_compiler_flags(jakt_runtime)
target_include_directories(jakt_runtime
  PRIVATE
   "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  PUBLIC
   "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/runtime>"
)

add_library(Jakt::jakt_runtime ALIAS jakt_runtime)
apply_output_rules(jakt_runtime)
target_link_libraries(jakt_runtime PRIVATE Threads::Threads)

add_library(jakt_main STATIC Main.cpp)
add_jakt_compiler_flags(jakt_main)
target_include_directories(jakt_main
  PRIVATE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  PUBLIC
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/runtime>"
)

add_library(Jakt::jakt_main ALIAS jakt_main)
apply_output_rules(jakt_main)

set_target_properties(jakt_runtime jakt_main PROPERTIES POSITION_INDEPENDENT_CODE ON)
