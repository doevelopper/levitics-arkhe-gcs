
project(levitics-arkhe-gcs CXX)

cmake_minimum_required( VERSION 3.11.3 FATAL_ERROR)

set(PROJECT_NAME_MAJOR_VERSION       3)
set(PROJECT_NAME_MINOR_VERSION       7)
set(PROJECT_NAME_MICRO_VERSION       0)
set(PROJECT_NAME_PATCH_VERSION       0)

set(PROJECT_VERSION_MAJOR       1)
set(PROJECT_VERSION_MINOR       5)
set(PROJECT_VERSION_PATCH       2)
set(PROJECT_VERSION_TWEAK       1101)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

set("BUILD_SHARED_LIBS" OFF CACHE INTERNAL "If enabled, shared libs will be built by default, otherwise static libs")

add_definitions(-DPROJECT_VERSION_MAJOR=1)
add_definitions(-DPROJECT_VERSION_MINOR=0)
add_definitions(-DPROJECT_VERSION_MICRO=0)
add_definitions(-DPROJECT_VERSION_PATCH=${PROJECT_NAME})

add_definitions(-DRELEASE_LEVEL="SNAPSHOOT") # SNAPSHOOT ,ALPHA , BETA , CANDIDATE , FINAL.
set(RELEASE_LEVEL "SNAPSHOOT")

add_definitions(-DAPPLICATIONNAME="${PROJECT_NAME} ${PROJECT_VERSION_PATCH}")
add_definitions(-DAPP_VERSION_STR="${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}.${${PROJECT_NAME}_MICRO_VERSION}")


list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/modules"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/toolChains"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/macros"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/config"
    "${CMAKE_SOURCE_DIR}/src/test/resources/config/modules"
)

set (NAMESPACE "GCS")

include(DefinePlatformSpecfic)
include(CompilerOption)
include(goals)
include(qt)
include(macros)
include(PreventInSourceBuilds)
#include(CodingStyle)
#include(CpplintWrapper)
#include(Cucumber)
#include(DocumentationTargets)
# include(PrintVariables)
getGitInfo()
TODAY(APP_BUILD_DATE)

include(TestBigEndian)
TEST_BIG_ENDIAN(IS_BIG_ENDIAN)

if(IS_BIG_ENDIAN)
     message(FATAL_ERROR "Big endian isn't supported !!!")
endif(IS_BIG_ENDIAN)

include(ProcessorCount)
ProcessorCount(NProc)

set(COPYRIGHT_YEAR ${APP_BUILD_DATE})

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Config.hpp.in"
	       #"${CMAKE_CURRENT_BINARY_DIR}/levitics/arkhe/gcs/Config.hpp"
	       "${CMAKE_BINARY_DIR}/levitics/app/Config.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Api.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/Api.hpp"
                @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/config/Defines.hpp.in"
               "${CMAKE_BINARY_DIR}/levitics/app/Defines.hpp"
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

get_property(cxx_known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)
get_property(c_known_features GLOBAL PROPERTY CMAKE_C_KNOWN_FEATURES)

include(WriteCompilerDetectionHeader)
write_compiler_detection_header(
    FILE ${CMAKE_BINARY_DIR}/levitics/app/CompilerDetection.hpp
    PREFIX GCS
#              [OUTPUT_FILES_VAR <output_files_var> OUTPUT_DIR <output_dir>]
    COMPILERS GNU 
    #    FEATURES  ${cxx_known_features} cxx_variadic_templates cxx_constexpr cxx_deleted_functions 
    #              cxx_final cxx_noexcept cxx_override cxx_alignas cxx_alignof
    #	      cxx_nullptr cxx_sizeof_member cxx_thread_local
    FEATURES  ${cxx_known_features}
    VERSION   "${CMAKE_VERSION}"
    PROLOG "//<prolog>"
    EPILOG "//<epilog>"
#              [ALLOW_UNKNOWN_COMPILERS]
#              [ALLOW_UNKNOWN_COMPILER_VERSIONS]
)


#find_package(Doxygen  
#   REQUIRED  dot
#   OPTIONAL_COMPONENTS mscgen dia
#)


add_subdirectory(src/main/cpp)
add_subdirectory(src/test/cpp)
#add_subdirectory(src/it)
