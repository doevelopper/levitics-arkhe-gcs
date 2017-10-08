include_directories(.)

add_subdirectory(levitics/osgi)


set(SOURCE_FILES
    levitics/app/GCSApplication
    levitics/app/Version
    levitics/app/View
    levitics/app/mainwindow
    levitics/app/MultiScreenManagement
    levitics/app/private/MainWindowPrivate
    levitics/app/private/GCSApplicationPrivate
    levitics/arkhe/gcs/EnvironmentVariablesManager
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

#https://cmake.org/Wiki/CMake/Tutorials/Object_Library
## A/CMakeLists.txt
# add_library(A OBJECT ${A_srcs})
## B/CMakeLists.txt
# add_library(B OBJECT ${B_srcs})
## CMakeLists.txt
# add_subdirectory(A)
# add_subdirectory(B)
# add_library(big ${other_srcs} $<TARGET_OBJECTS:A> $<TARGET_OBJECTS:B>)


add_executable(${PROJECT_NAME}.bin
    main.cpp
)
set_target_properties(${PROJECT_NAME}.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(${PROJECT_NAME} osgi )
target_link_libraries(${PROJECT_NAME}.bin ${PROJECT_NAME} )
