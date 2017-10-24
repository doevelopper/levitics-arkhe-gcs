include_directories(.)

set(SOURCE_FILES
    GcsTest
    # levitics/arkhe/gcs/ApplicationTest
    # levitics/arkhe/gcs/errors-handling/
    # levitics/osgi/core/logger/
    # levitics/osgi/core/workflow/WorkflowStepMock
    # levitics/osgi/core/workflow/WorkflowStepSignals
    # levitics/osgi/core/workflow/private/WorkflowStepMockPrivate
    # levitics/osgi/core/workflow/private/WorkflowStepSignalsPrivate

)

add_executable(${PROJECT_NAME}Test.bin runTest ${SOURCE_FILES} )
# set_target_properties(${PROJECT_NAME}Test.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(${PROJECT_NAME}Test.bin 
    ${PROJECT_NAME}
	${THIRD_PARTY_LIB}  
	${TEST_THIRD_PARTY_LIB}
)
