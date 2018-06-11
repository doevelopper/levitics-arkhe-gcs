
if (NOT TARGET CUCUMBER-CPP::CUCUMBER-CPP)
    find_package(Cucumber-cpp REQUIRED)
endif()

set(cppsrc
    levitics/arkhe/gcs/features/step_definitions/step_definitions
)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

add_library(${PROJECT_NAME}-it STATIC ${cppsrc})

target_link_libraries(${PROJECT_NAME}-it
    ${PROJECT_NAME}
#    ${THIRD_PARTY_LIB}
#    ${TEST_THIRD_PARTY_LIB}
)

add_executable(levitics.arkhe.gcs.bin-It-steps-Test 
    levitics/arkhe/gcs/features/step_definitions/step_definitions
)

target_link_libraries( levitics.arkhe.gcs.bin-It-steps-Test
    PUBLIC
        CUCUMBER-CPP::CUCUMBER-CPP    
)

add_custom_target(
    levitics.arkhe.gcs.bin-It-Test
#   DEPENDS ${PROJECT_NAME}.bin-Test
#   COMMAND ${PROJECT_NAME}.bin-It-Test --port=3902 >/dev/null & cucumber _2.0.0_ ${CMAKE_CURRENT_SOURCE_DIR}/features 
    COMMENT "Running ${PROJECT_NAME}.bin-It-steps-Test integration test"
)

#add_custom_command(TARGET RunAllTests
#    POST_BUILD
#    COMMAND RunTests
#    COMMAND SpeakerSteps 3902 &
#    COMMAND cucumber -s ${CMAKE_SOURCE_DIR}/features
#)

