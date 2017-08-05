include_directories(.)

set(SOURCE_FILES
	#levitics/arkhe/gcs/ApplicationTest
        GcsTest
)

add_executable(${PROJECT_NAME}Test.bin runTest ${SOURCE_FILES} )

target_link_libraries( 
    ${PROJECT_NAME}Test.bin 
    ${PROJECT_NAME} 
    benchmark
    gmock 
    gtest 
)
