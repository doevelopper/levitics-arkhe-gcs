

if (NOT TARGET GTest::GTest AND NOT TARGET GMock::GMock)
    find_package(GoogleTestFwk REQUIRED)
endif()

add_library(levitics.arkhe.gcs.test STATIC 
    GcsTest
    levitics/arkhe/gcs/app/GCSApplicationTest
)

add_dependencies(levitics.arkhe.gcs.test test-compile)

target_include_directories(levitics.arkhe.gcs.test 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(levitics.arkhe.gcs.test
    PUBLIC
        levitics.arkhe.gcs.main
        GTest::Main
        GMock::GMock
)

add_executable(levitics.arkhe.gcs.test.bin 
    runTest 
    #${SOURCE_FILES} 
)

#set_target_properties(levitics.arkhe.gcs.test.bin PROPERTIES 
#    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
#)

target_link_libraries(levitics.arkhe.gcs.test.bin
    levitics.arkhe.gcs.test
)

#include(GoogleTest)
#gtest_discover_tests(levitics.arkhe.gcs.test.bin
#    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
#    TEST_PREFIX "levitics.arkhe.gcs.test.bin:-: "
#    TEST_SUFFIX ----
#    PROPERTIES LABELS EDAC TEST
#    DISCOVERY_TIMEOUT 10
#    EXTRA_ARGS --iterration 1 --outputpath ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} --module levitics.arkhe.gcs.test
#)
