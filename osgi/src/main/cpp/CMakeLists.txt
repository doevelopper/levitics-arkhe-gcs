
set(cppsrc
    levitics/arkhe/gcs/osgi/core/logger/private/LoggerPrivate
    levitics/arkhe/gcs/osgi/core/logger/Logger
    levitics/arkhe/gcs/osgi/core/edac/private/BackTracePrivate
    levitics/arkhe/gcs/osgi/core/edac/Exception
    levitics/arkhe/gcs/osgi/core/edac/Demangler
    levitics/arkhe/gcs/osgi/core/edac/BackTrace
 )

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
# include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})
target_link_libraries( ${PROJECT_NAME}-osgi ${THIRD_PARTY_LIB}  Qt5::Widgets Qt5::Svg )

# target_link_libraries( osgi log4cxx apr-1 aprutil-1 expat  Qt5::Widgets Qt5::Svg )
# setup include directories 
target_include_directories(${PROJECT_NAME}-osgi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# target_include_directories(${PROJECT_NAME}-osgi PUBLIC 
	# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
 	# $<INSTALL_INTERFACE:include>
# )

# setup export preprocessor definitions
# if(BUILD_SHARED_LIBS)
  # target_compile_definitions(${PROJECT_NAME}-osgi PRIVATE 	OSGI_EXPORTS) 
  # target_compile_definitions(${PROJECT_NAME}-osgi INTERFACE OSGI_IMPORTS) 
# endif()

# include_directories(.)

# set(SOURCE_FILES
    # core/error-handling/Exception
    # core/error-handling/BackTrace
    # core/error-handling/private/BackTracePrivate
    # core/error-handling/Demangler

    # core/workflow/ForwardAndBackwardSteps
    # core/workflow/Workflow
    # core/workflow/WorkflowStep
    # core/workflow/private/WorkflowPrivate
    # core/workflow/private/WorkflowStepPrivate
    # core/workflow/WorkflowIntrastepTransitionEvent
    # core/workflow/WorkflowIntrastepTransition
    # core/workflow/WorkflowInterstepTransitionEvent
    # core/workflow/WorkflowInterstepTransition


# )


# add_library( osgi ${SOURCE_FILES})
# target_link_libraries( osgi log4cxx apr-1 aprutil-1 expat  Qt5::Widgets Qt5::Svg )

#https://cmake.org/Wiki/CMake/Tutorials/Object_Library
## A/CMakeLists.txt
# add_library(A OBJECT ${A_srcs})
## B/CMakeLists.txt
# add_library(B OBJECT ${B_srcs})
## CMakeLists.txt
# add_subdirectory(A)
# add_subdirectory(B)
# add_library(big ${other_srcs} $<TARGET_OBJECTS:A> $<TARGET_OBJECTS:B>)

# target_link_libraries(${PROJECT_NAME} log4cxx apr-1 aprutil-1 expat  Qt5::Widgets Qt5::Svg )
# target_link_libraries(${PROJECT_NAME}.bin log4cxx apr-1 aprutil-1 expat  Qt5::Widgets Qt5::Svg )
