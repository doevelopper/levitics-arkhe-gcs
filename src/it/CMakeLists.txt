set(cppsrc
    levitics/arkhe/gcs/features/step_definitions/step_definitions
)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

# include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(${PROJECT_NAME}-it STATIC ${cppsrc})

target_link_libraries(${PROJECT_NAME}-it
    ${PROJECT_NAME}
#    ${THIRD_PARTY_LIB}
#    ${TEST_THIRD_PARTY_LIB}
)

#add_executable(${PROJECT_NAME}-itTest.bin runTest ${SOURCE_FILES} )
#target_link_libraries(${PROJECT_NAME}-itTest.bin
#    ${PROJECT_NAME}-it
#    ${THIRD_PARTY_LIB}
#    ${TEST_THIRD_PARTY_LIB}
#)
