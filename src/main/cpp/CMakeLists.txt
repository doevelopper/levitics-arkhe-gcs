include_directories(.)

set(SOURCE_FILES
    # levitics/app/GCSApplication
    # levitics/app/Version
    # levitics/app/View
    # levitics/app/mainwindow
    levitics/arkhe/gcs/app/MultiScreenManagement
    levitics/arkhe/gcs/app/ScreensDimensions
    # levitics/app/private/MainWindowPrivate
    # levitics/app/private/GCSApplicationPrivate
    # levitics/arkhe/gcs/EnvironmentVariablesManager
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB} )
#https://cmake.org/Wiki/CMake/Tutorials/Object_Library
## A/CMakeLists.txt
# add_library(A OBJECT ${A_srcs})
## B/CMakeLists.txt
# add_library(B OBJECT ${B_srcs})
## CMakeLists.txt
# add_subdirectory(A)
# add_subdirectory(B)
# add_library(big ${other_srcs} $<TARGET_OBJECTS:A> $<TARGET_OBJECTS:B>)


# add_executable(${PROJECT_NAME}.bin
    # main.cpp
# )
# set_target_properties(${PROJECT_NAME}.bin PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
# target_link_libraries(${PROJECT_NAME}.bin ${PROJECT_NAME} ${TEST_THIRD_PARTY_LIB})
# target_link_libraries(${PROJECT_NAME}.bin ${PROJECT_NAME} )
# target_compile_definitions(${PROJECT_NAME}.bin PRIVATE "EXPORT_API=Q_DECL_EXPORT")

#add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})
#target_link_libraries( ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}
#    Qt5::Network Qt5::Core Qt5::Widgets Qt5::Svg
#    Qt5::Quick Qt5::Xml Qt5::OpenGL Qt5::WebKit Qt5::WebKitWidgets
#)
#target_compile_features(${PROJECT_NAME}-osgi PUBLIC
#    cxx_constexpr
#    cxx_variadic_templates
#    cxx_final
#    cxx_override
#    )
#target_include_directories(${PROJECT_NAME}-osgi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
