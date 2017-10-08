include_directories(.)

set(SOURCE_FILES
    core/logger/private/LoggerPrivate
    core/logger/Logger

    core/error-handling/Exception
    core/error-handling/BackTrace
    core/error-handling/private/BackTracePrivate
    core/error-handling/Demangler

    core/workflow/private/WorkflowPrivate
    core/workflow/private/WorkflowStepPrivate
    core/workflow/WorkflowIntrastepTransitionEvent
    core/workflow/WorkflowIntrastepTransition
    core/workflow/WorkflowInterstepTransitionEvent
    core/workflow/WorkflowInterstepTransition

)


add_library( osgi ${SOURCE_FILES})
target_link_libraries( osgi log4cxx apr-1 aprutil-1 expat  Qt5::Widgets Qt5::Svg )

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
