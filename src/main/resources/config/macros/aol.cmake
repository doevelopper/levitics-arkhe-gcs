#set(platform_dir ${CMAKE_SYSTEM_NAME}${platform_bits}-${CMAKE_CXX_COMPILER_ID}${CMAKE_CXX_COMPILER_VERSION})
# set(AOL "${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}_${CMAKE_HOST_SYSTEM_NAME}-GCC_${CMAKE_CXX_COMPILER_VERSION}")

# if ("${UNAME}")
    # getuname(osname -s)
    # getuname(osrel -r)
    # getuname(cpu -m)
# else ("${UNAME}")
    # set(osname "${CMAKE_HOST_SYSTEM_NAME}")
    # set(osrel  "${CMAKE_HOST_SYSTEM_VERSION}")
    # set(cpu    "${CMAKE_HOST_SYSTEM_PROCESSOR}")
# endif("${UNAME}")

set(AOL "${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}_GCC_${CMAKE_CXX_COMPILER_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")

#set(platform_dir ${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}_${CMAKE_HOST_SYSTEM_NAME}-GCC_${CMAKE_CXX_COMPILER_VERSION}-${CMAKE_BUILD_TYPE})

set(BUILD_DIRECTORY ${CMAKE_BINARY_DIR})
set(TARGET_BUILD_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE})
set(ROOT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(ROOT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX ${AOL}-${CMAKE_BUILD_TYPE})

#foreach(config DEBUG RELEASE RELWITHDEBINFO MINSIZEREL SwQA)
#     foreach(var CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${config} CMAKE_LIBRARY_OUTPUT_DIRECTORY_${config} CMAKE_RUNTIME_OUTPUT_DIRECTORY_${config})
#         set(${var} "${TARGET_BUILD_DIRECTORY}-${config}")
#         string(TOLOWER "${${var}}" ${var})
##         file(MAKE_DIRECTORY ${var})
#     endforeach()
# endforeach()


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/bin)
