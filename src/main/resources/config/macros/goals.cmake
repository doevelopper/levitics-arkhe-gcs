
if(ENABLE_FORMATING_STYLE)
    if(NOT TARGET style)
        add_custom_target(style
            COMMENT "Prettying source code"
            )
    endif(NOT TARGET style)
else(ENABLE_FORMATING_STYLE)
    add_custom_target(style
        COMMAND ${CMAKE_COMMAND} -E echo "Source code beautifier tool is disabled"
    )
endif(ENABLE_FORMATING_STYLE)

if(ENABLE_CYCLOMATIC_COMPLEXITY)
    if(NOT TARGET cyclomatic)
        add_custom_target(cyclomatic
            COMMENT "Cyclomatic Complexity Analyzer."
            )
    endif(NOT TARGET cyclomatic)
else(ENABLE_CYCLOMATIC_COMPLEXITY)
    add_custom_target(cyclomatic
        COMMAND ${CMAKE_COMMAND} -E echo "Source code complexity analyser tool is disabled"
    )
endif(ENABLE_CYCLOMATIC_COMPLEXITY)


if(ENABLE_CPPCHECK)
    if(NOT TARGET cppcheck)
        add_custom_target(cppcheck
            COMMENT "Static code analysis."
            )
    endif(NOT TARGET cppcheck)
else(ENABLE_CPPCHECK)
    add_custom_target(cppcheck
        COMMAND ${CMAKE_COMMAND} -E echo "Static analysis tool is disabled"
    )
endif(ENABLE_CPPCHECK)

if(ENABLE_CPPLINT)
    if(NOT TARGET lint)
        add_custom_target(lint
            COMMENT "Check the C++ source code to analyze it for syntax errors and other faults."
            )
    endif(NOT TARGET lint)
else(ENABLE_CPPLINT)
    add_custom_target(lint
        COMMAND ${CMAKE_COMMAND} -E echo "Test coverage is disabled"
    )
endif(ENABLE_CPPLINT)

if(ENABLE_COVERAGE)
    if(NOT TARGET coverage)
        add_custom_target(coverage
            COMMENT "Running coverage report."
            )
    endif(NOT TARGET coverage)
else(ENABLE_COVERAGE)
    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E echo "Test coverage is disabled"
    )
endif(ENABLE_COVERAGE)


if(ENABLE_QA_CHECK)
    if(NOT TARGET qa-check)
        ADD_CUSTOM_TARGET(qa-check
            COMMENT "Software quality assurance: Style -> CPPCheck -> Cyclomatic -> CPPlint -> Coverage"
        )
        add_dependencies(qa-check coverage style cppcheck cyclomatic lint)
    endif(NOT TARGET qa-check)
else(ENABLE_QA_CHECK)
    add_custom_target(qa-check 
        COMMAND ${CMAKE_COMMAND} -E echo "Software quality assurance disabled"
    )
endif(ENABLE_QA_CHECK)

add_custom_target (distclean
    COMMAND rm -vf ${CMAKE_SOURCE_DIR}/*.log
    COMMAND rm -vf ${CMAKE_SOURCE_DIR}/Makefile
    COMMAND rm -vf ${CMAKE_SOURCE_DIR}/install_manifest.txt
    COMMAND rm -vf ${CMAKE_SOURCE_DIR}/cmake_install.cmake
    COMMAND find ${CMAKE_SOURCE_DIR} -type f -name CMakeCache.txt | xargs -r rm -vf
    COMMAND find ${CMAKE_SOURCE_DIR} -type d -name CMakeFiles | xargs -r rm -rvf
    COMMAND find ${CMAKE_SOURCE_DIR} -type f -name "*.marks" | xargs -r rm -vf
    COMMENT "Cleaning target"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

