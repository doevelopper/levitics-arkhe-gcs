
set(cppsrc
    levitics/arkhe/gcs/osgi/core/logger/LoggerTest
    levitics/arkhe/gcs/osgi/core/workflow/private/WorkflowStepMockPrivate
    levitics/arkhe/gcs/osgi/core/workflow/private/WorkflowStepSignalsPrivate
    levitics/arkhe/gcs/osgi/core/workflow/WorkflowStepMock
    levitics/arkhe/gcs/osgi/core/workflow/WorkflowStepSignals
    levitics/arkhe/gcs/osgi/core/workflow/WorkflowTest
 )

add_library(${PROJECT_NAME}-osgiTest STATIC ${cppsrc})

# setup include directories 
target_include_directories(${PROJECT_NAME}-osgiTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries( ${PROJECT_NAME}-osgiTest ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}  ${TEST_THIRD_PARTY_LIB} Qt5::Widgets Qt5::Svg )

# target_include_directories(${PROJECT_NAME}-osgi PUBLIC 
	# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
 	# $<INSTALL_INTERFACE:include>
# )

# setup export preprocessor definitions
# if(BUILD_SHARED_LIBS)
  # target_compile_definitions(${PROJECT_NAME}-osgi PRIVATE 	OSGI_EXPORTS) 
  # target_compile_definitions(${PROJECT_NAME}-osgi INTERFACE OSGI_IMPORTS) 
# endif()

## Testing
# add_executable(${PROJECT_NAME}-osgiTest.bin 	tests/fareweller_test.cpp)
# target_link_libraries(${PROJECT_NAME}-osgiTest.bin ${PROJECT_NAME}-osgiTest)
# add_test(${PROJECT_NAME}-osgiTest.bin ${PROJECT_NAME}-osgiTest.bin)

#ADD_EXECUTABLE(${LIBNAME}.Tests ${TESTS_SOURCES})
#TARGET_LINK_LIBRARIES(${LIBNAME}.Tests ${TARGET_DEPENDENCIES} ${TARGET_3RDPARTY_DEPENDENCIES} ${LIBNAME})
#ADD_TEST(   NAME ${LIBNAME}.Tests
#            COMMAND ${LIBNAME}.Tests
#            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
