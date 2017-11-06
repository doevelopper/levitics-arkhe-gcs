
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

add_library(${PROJECT_NAME}Test STATIC ${cppsrc})
target_include_directories(${PROJECT_NAME}Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}Test
    ${PROJECT_NAME}
    ${THIRD_PARTY_LIB}
    ${TEST_THIRD_PARTY_LIB}
)

add_executable(${PROJECT_NAME}Test.bin runTest ${SOURCE_FILES} )

### set_target_properties(${PROJECT_NAME}Test.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(${PROJECT_NAME}Test.bin
    ${PROJECT_NAME}Test
)

## setup include directories
#target_include_directories(${PROJECT_NAME}-osgiTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries( ${PROJECT_NAME}-osgiTest ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}
#    ${TEST_THIRD_PARTY_LIB} Qt5::Widgets Qt5::Svg )
