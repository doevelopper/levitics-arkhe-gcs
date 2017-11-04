project(levitics-arkhe-gcs CXX)
cmake_minimum_required( VERSION 3.7 FATAL_ERROR)


set(PROJECT_NAME_MAJOR_VERSION       3)
set(PROJECT_NAME_MINOR_VERSION       7)
set(PROJECT_NAME_MICRO_VERSION       0)
set(PROJECT_NAME_PATCH_VERSION       0)

set(PROJECT_VERSION_MAJOR       1)
set(PROJECT_VERSION_MINOR       5)
set(PROJECT_VERSION_PATCH       2)
set(PROJECT_VERSION_TWEAK       1101)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_definitions(-DPROJECT_VERSION_MAJOR=1)
add_definitions(-DPROJECT_VERSION_MINOR=0)
add_definitions(-DPROJECT_VERSION_MICRO=0)
add_definitions(-DPROJECT_VERSION_PATCH=${PROJECT_NAME})

add_definitions(-DRELEASE_LEVEL="SNAPSHOOT") # SNAPSHOOT ,ALPHA , BETA , CANDIDATE , FINAL.

add_definitions(-DAPPLICATIONNAME="${PROJECT_NAME} ${PROJECT_VERSION_PATCH}")
add_definitions(-DAPP_VERSION_STR="${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}.${${PROJECT_NAME}_MICRO_VERSION}")

option(ENABLE_QA_CHECK                  "Software quality. Conformance to one or more standards"    OFF)
option(ENABLE_COVERAGE                  "Build the project with coverage support"                   OFF)
option(ENABLE_CPPLINT                   "Ensure that code conforms to Google's coding style guides" OFF)
option(ENABLE_FORMATING_STYLE           "Code Beautifier"                                           OFF)
option(ENABLE_CYCLOMATIC_COMPLEXITY     "Cyclomatic Complexity Analyzer"                            OFF)
option(ENABLE_CPPCHECK                  "Static code analysis tool "                                OFF)
option(ANALYZE_MEMORY                   "Dynamic analyzer: detector of uninitialized reads."        OFF)
option(ANALYZE_ADDRESS                  "Dynamic analyzer: fast memory error detector. "            OFF)
option(ANALYZE_THREAD                   "Dynamic analyzer: tool that detects data races. "          OFF)
option(ANALYZE_UNDEFINED                "Dynamic analyzer: undefined behavior checker. "            OFF)
option(ANALYZE_DATAFLOW                 "Dynamic analyzer: general dynamic dataflow analysis."      OFF)
option(WARNINGS_ARE_ERRORS              "Treat warnings as errors"                                  OFF)
option(WARNINGS_ANSI_ISO                "Issue all the mandatory diagnostics Listed in C standard"  ON)
option(ENABLE_SANITIZE                  "Sanitize build"                                            OFF)
option(ENABLE_TIDY                      "Use clang-tidy"                                            OFF)
option(ENABLE_STATIC                    "Make a static build"                                       OFF)
option(ENABLE_COVERAGE                  "Run code coverage"                                         OFF)
option(ENABLE_EXAMPLES                  "Build examples"                                            OFF)
option(ENABLE_CI                        "Continuous integration run"                                OFF)
option(ENABLE_LTO                       "Link-time optimizations. Fails on Windows."                OFF)


list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/modules"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/toolChains"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/macros"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/config"
    "${CMAKE_SOURCE_DIR}/src/test/resources/config/modules"
)

set (NAMESPACE "GCS")

include(DefinePlatformSpecfic)
include(aol)
include(CompilerOption)
include(goals)
include(CMakeSettings)
include(qt)
include(macros)
include(PreventInSourceBuilds)
include(PreventInSourceBuilds)
include(CodingStyle)
#include(DocumentationTargets)
# include(PrintVariables)
getGitInfo()
TODAY(APP_BUILD_DATE)

set(THIRD_PARTY_LIB ${CMAKE_THREAD_LIBS_INIT} apr-1 expat aprutil-1 log4cxx )
set(TEST_THIRD_PARTY_LIB gmock gtest benchmark)
set(TEST_THIRD_PARTY_LIB_MAIN ${TEST_THIRD_PARTY_LIB} gmock_main)
set(INTEG_TEST_THIRD_PARTY_LIB ${TEST_THIRD_PARTY_LIB} cucumber-cpp-nomain)
set(INTEG_TEST_THIRD_PARTY_LIB_MAIN ${TEST_THIRD_PARTY_LIB} cucumber-cpp)

set(COPYRIGHT_YEAR ${APP_BUILD_DATE})

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Config.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/Config.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Api.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/Api.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Defines.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/Defines.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/AppInfo.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/AppInfo.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Version.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/Version.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Version.cpp.in"
                "${CMAKE_BINARY_DIR}/levitics/app/Version.cpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/GitRevision.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/GitRevision.hpp"
               @ONLY)

include_directories(${CMAKE_BINARY_DIR})

if(BUILD_MUDULE_LIKE)

else(BUILD_MUDULE_LIKE)
    add_subdirectory(osgi)
endif(BUILD_MUDULE_LIKE)

#if(ENABLE_FORMATING_STYLE)
#    apply_style_targets(
#        ${PROJECT_NAME}
#        ${CMAKE_CURRENT_BINARY_DIR}
#    )
#endif(ENABLE_FORMATING_STYLE)

add_subdirectory(src/main/cpp)
# add_subdirectory(src/test/cpp)
# add_subdirectory(src/it)
