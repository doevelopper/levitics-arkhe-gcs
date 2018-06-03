
set(cppsrc
    GcsTest
#    # levitics/arkhe/gcs/ApplicationTest
#    # levitics/arkhe/gcs/edac/
#    # levitics/osgi/core/logger/
#    # levitics/osgi/core/workflow/WorkflowStepMock
#    # levitics/osgi/core/workflow/WorkflowStepSignals
#    # levitics/osgi/core/workflow/private/WorkflowStepMockPrivate
#    # levitics/osgi/core/workflow/private/WorkflowStepSignalsPrivate

)

if (NOT TARGET GTest::GTest AND NOT TARGET GMock::GMock)
    find_package(GoogleTestFwk REQUIRED)
endif()

add_library(levitics.arkhe.gcs.test STATIC 
    GcsTest
)
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

add_executable(levitics.arkhe.gcs.test.bin runTest 
    ${SOURCE_FILES} 
)

### set_target_properties(${PROJECT_NAME}Test.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(levitics.arkhe.gcs.test.bin
    levitics.arkhe.gcs.test
)

## setup include directories
#target_include_directories(${PROJECT_NAME}-osgiTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries( ${PROJECT_NAME}-osgiTest ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}
#    ${TEST_THIRD_PARTY_LIB} Qt5::Widgets Qt5::Svg )
