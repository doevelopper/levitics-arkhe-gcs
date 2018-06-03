#       levitics-arkhe-gcs/src/main/resources/config/modules/FindGoogleTestFwk.cmake
#
#               Copyright (c) 2014-2018  A.H.L
#
#        Permission is hereby granted, free of charge, to any person obtaining
#        a copy of this software and associated documentation files (the
#        "Software"), to deal in the Software without restriction, including
#        without limitation the rights to use, copy, modify, merge, publish,
#        distribute, sublicense, and/or sell copies of the Software, and to
#        permit persons to whom the Software is furnished to do so, subject to
#        the following conditions:
#
#        The above copyright notice and this permission notice shall be
#        included in all copies or substantial portions of the Software.
#
#        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#        EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#        NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#        LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#        OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#        WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


qt5_add_resources(resource_headers 
    ${CMAKE_CURRENT_LIST_DIR}/../resources/resources.qrc
)

qt5_wrap_ui(resource_headers_forms
    ${CMAKE_CURRENT_LIST_DIR}/../resources/uis/connectionnotificationwidget.ui
)

# qt5_wrap_cpp
# qt5_wrap_ui
# qt5_add_binary_resources
# qt5_add_resources
# qt5_add_translation

set(SOURCE_FILES
#    levitics/arkhe/gcs/app/GCSApplication
#    levitics/arkhe/gcs/app/private/GCSApplicationPrivate
    # levitics/app/Version
    # levitics/app/View
    # levitics/app/mainwindow
#    levitics/arkhe/gcs/app/MultiScreenManagement
#    levitics/arkhe/gcs/app/ScreensDimensions
    # levitics/app/private/MainWindowPrivate
     levitics/arkhe/gcs/EnvironmentVariablesManager
#    ${resource_headers_forms}
#    ${resource_headers}
)

# qt5_add_resources(resource_headers ${SRC_DIR}/src/main/resources/resources.qrc)

if (NOT TARGET  LOG4CXX::LOG4CXX)
    find_package(Log4cxx REQUIRED)
endif()

add_library(levitics.arkhe.gcs.main STATIC ${SOURCE_FILES}
)

option(EXCLUDE_DEPRECATED "Exclude deprecated parts of the library" TRUE)
if (EXCLUDE_DEPRECATED)
    set(NO_BUILD_DEPRECATED DEFINE_NO_DEPRECATED)
endif()

include(GenerateExportHeader)
generate_export_header(levitics.arkhe.gcs.main
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/levitics/arkhe/gcs/Export.hpp"
    INCLUDE_GUARD_NAME LEVITICS_ARKHE_GCS_EXPORT_HPP
    # EXPORT_MACRO_NAME API_DECLS
    #BASE_NAME EDAC 
    #PREFIX_NAME EDAC_
    #STATIC_DEFINE BUILT_AS_STATIC
    DEPRECATED_MACRO_NAME LEV_AKH_GCS_DEPRECATED
    ${NO_BUILD_DEPRECATED}
)

target_compile_options(levitics.arkhe.gcs.main
    INTERFACE
        #-std=c++17
        $<$<CONFIG:Debug>:-g3 -O0 -fstack-protector>
        $<$<CONFIG:Release>:-g0 -O2>
    PUBLIC 
        $<$<COMPILE_LANGUAGE:CXX>: -W -Wall -Wextra -Weffc++ -Wpedantic -fmax-errors=5 -Werror=shadow -fdiagnostics-parseable-fixits>
        $<$<CONFIG:Debug>: -O0 -g -D_DEBUG -D_FORTIFY_SOURCE=2 -fno-strict-aliasing -fno-omit-frame-pointer>
        $<$<CONFIG:Release>:-g0 -O2>
        $<$<CONFIG:Coverage>:-O0  -fprofile-arcs -ftest-coverage --coverage>
        $<$<CONFIG:Profile>:-fsanitize=memory -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer>
       
)

target_compile_features(levitics.arkhe.gcs.main
    PUBLIC
        cxx_std_17
        cxx_strong_enums
        cxx_variadic_templates
        cxx_nullptr
        cxx_alias_templates
        cxx_auto_type
        cxx_constexpr
        cxx_defaulted_functions
        cxx_final
        cxx_lambdas
        cxx_noexcept
        cxx_nullptr
        cxx_rvalue_references
        cxx_thread_local
        cxx_variadic_templates
        cxx_override
    PRIVATE
        cxx_lambdas
        cxx_range_for
        $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
)


target_link_libraries(levitics.arkhe.gcs.main
    PUBLIC
        LOG4CXX::LOG4CXX
        Qt5::Concurrent
        Qt5::Core Qt5::Charts
        Qt5::DataVisualization
        Qt5::Gui
        # Qt5::Gamepad
        # Qt5::Help
        Qt5::Location
        Qt5::Network Qt5::NetworkAuth
        Qt5::Multimedia	Qt5::MultimediaWidgets
        Qt5::OpenGL Qt5::OpenGLExtensions
        Qt5::Positioning Qt5::Purchasing
        Qt5::Quick Qt5::Qml Qt5::Quick Qt5::QuickControls2 Qt5::QuickWidgets
        Qt5::Svg
    #    Qt5::WebKit Qt5::WebKitWidgets 
        Qt5::Widgets 
        Qt5::Xml 
)

add_executable(levitics.arkhe.gcs.main.bin
    main.cpp
)
target_link_libraries(levitics.arkhe.gcs.main.bin 
    levitics.arkhe.gcs.main
)

target_include_directories(levitics.arkhe.gcs.main
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/levitics/arkhe/gcs>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/levitics/arkhe/gcs>
)

if(NOT TARGET LEVITICS-ARKHE-GCS-MAIN::LEVITICS-ARKHE-GCS-MAIN)
    add_library(LEVITICS-ARKHE-GCS-MAIN::LEVITICS-ARKHE-GCS-MAIN UNKNOWN IMPORTED)
    set_target_properties(LEVITICS-ARKHE-GCS-MAIN::LEVITICS-ARKHE-GCS-MAIN PROPERTIES
        # EXCLUDE_FROM_ALL 1
        INTERFACE_COMPILE_DEFINITIONS "${EDAC_MAIN_DEFINITIONS}"
        IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
        IMPORTED_LOCATION "${CMAKE_INSTALL_LIBDIR}/levitics.arkhe.gcs.main.a"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/levitics/arkhe/gcs"
        INTERFACE_LINK_LIBRARIES "LOG4CXX::LOG4CXX"
    )
endif(NOT TARGET LEVITICS-ARKHE-GCS-MAIN::LEVITICS-ARKHE-GCS-MAIN)
