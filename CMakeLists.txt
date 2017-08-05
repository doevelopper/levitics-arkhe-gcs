project(arkhe-gcs CXX)
cmake_minimum_required( VERSION 3.7 FATAL_ERROR)

set(${PROJECT_NAME}_MAJOR_VERSION       "${MAJOR}")
set(${PROJECT_NAME}_MINOR_VERSION       "${MINOR}")
set(${PROJECT_NAME}_MICRO_VERSION       "${MICRO}")
set(${PROJECT_NAME}_PATCH_VERSION       "${PATCH}")
set(${PROJECT_NAME}_REVISION_VERSION    "${REV}")


add_definitions(-DPROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_definitions(-DPROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_definitions(-DPROJECT_VERSION_MICRO=${PROJECT_VERSION_MICRO})
add_definitions(-DPROJECT_VERSION_PATCH=${PROJECT_NAME})

add_definitions(-DAPPLICATIONNAME=${PROJECT_VERSION_PATCH})
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
include(DocumentationTargets)
include(PrintVariables)
getGitInfo(GIT_REVISION GIT_STATE GIT_DATE REL)
TODAY(APP_BUILD_DATE)

set(THIRD_PARTY_LIB ${CMAKE_THREAD_LIBS_INIT} apr-1 expat aprutil-1 log4cxx )
set(TEST_THIRD_PARTY_LIB gmock gtest benchmark)
set(INTEG_TEST_THIRD_PARTY_LIB )

add_definitions(-DCOPYRIGHT_YEAR=${APP_BUILD_DATE})
add_definitions(-DGIT_REVISION=${GIT_REVISION})
add_definitions(-DVERSION_COMMIT=${GIT_REVISION})
add_definitions(-DGIT_REVISION=${GIT_REVISION})

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/gcsExport.hpp.in"
               "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/gcsExport.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Api.hpp.in"
               "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/app/Api.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Defines.hpp.in"
               "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/Defines.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/AppInfo.hpp.in"
               "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/app/AppInfo.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Version.hpp.in"
               "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/app/Version.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Version.cpp.in"
                "${CMAKE_SOURCE_DIR}/src/main/cpp/levitics/app/Version.cpp"
                @ONLY)

add_subdirectory(src/main/cpp)
add_subdirectory(src/test/cpp)
add_subdirectory(src/it)
