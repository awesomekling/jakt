set(RUNTIME_SOURCES
    IO/File.cpp
    Jakt/PrettyPrint.cpp
    Jakt/String.cpp
    Jakt/StringBuilder.cpp
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