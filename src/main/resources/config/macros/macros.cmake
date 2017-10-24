macro (TODAY RESULT)
    if (WIN32)
        execute_process(COMMAND "cmd" " /C date /T" OUTPUT_VARIABLE ${RESULT})
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}})
    elseif(UNIX)
        execute_process(COMMAND "date" "+%d/%m/%Y" OUTPUT_VARIABLE ${RESULT})
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}})
    else (WIN32)
        message(SEND_ERROR "date not implemented")
        set(${RESULT} 000000)
    endif (WIN32)
endmacro (TODAY)

macro(getuname name flag)
	find_program(UNAME NAMES uname)
    exec_program("${UNAME}" ARGS "${flag}" OUTPUT_VARIABLE "${name}")
endmacro(getuname)

function(getGitInfo)
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.git)
        set(GIT_EXECUTABLE "git")

        execute_process( COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_REVISION 
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process( COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_HASH
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process( COMMAND ${GIT_EXECUTABLE} config --get remote.origin.url
            OUTPUT_VARIABLE GIT_ORIGIN_URL 
            OUTPUT_STRIP_TRAILING_WHITESPACE
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

        execute_process( COMMAND ${GIT_EXECUTABLE} config --get remote.root.url
            OUTPUT_VARIABLE GIT_ROOT_URL 
            OUTPUT_STRIP_TRAILING_WHITESPACE
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

        execute_process( COMMAND ${GIT_EXECUTABLE} branch --contains HEAD
            OUTPUT_VARIABLE GIT_BRANCH 
            OUTPUT_STRIP_TRAILING_WHITESPACE
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

        execute_process(COMMAND  "${GIT_EXECUTABLE}" log -1 --format=%ad --date=local
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            OUTPUT_VARIABLE GIT_DATE
            ERROR_QUIET 
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process(COMMAND  "${GIT_EXECUTABLE}" rev-list HEAD --count
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            OUTPUT_VARIABLE NB_GIT_COMMIT
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process(COMMAND  "${GIT_EXECUTABLE}" rev-list --all --count
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            OUTPUT_VARIABLE ALL_GIT_COMMIT_COUNT
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process(COMMAND  "${GIT_EXECUTABLE}" log -1 --format=%s
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            OUTPUT_VARIABLE GIT_COMMIT_SUBJECT
            ERROR_QUIET 
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        execute_process( COMMAND "${GIT_EXECUTABLE}" diff-index --quiet HEAD --
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            RESULT_VARIABLE res
            OUTPUT_VARIABLE out
            ERROR_QUIET 
            OUTPUT_STRIP_TRAILING_WHITESPACE)

            if(res EQUAL 0)
                set(${REL} "GA")
            else()
                set(${REL} "-SNAPSHOOT")
            endif()

            set(GIT_REVISION ${GIT_REVISION} PARENT_SCOPE)
            set(VERSION_COMMIT ${GIT_STATE_ALWAYS} PARENT_SCOPE)
            set(GIT_ORIGIN_URL ${GIT_ORIGIN_URL} PARENT_SCOPE)
            set(GIT_COMMIT_SUBJECT ${GIT_COMMIT_SUBJECT} PARENT_SCOPE)
            set(GIT_DATE ${GIT_DATE} PARENT_SCOPE)
            set(GIT_BRANCH ${GIT_BRANCH} PARENT_SCOPE)
            set(NB_COMMIT ${NB_GIT_COMMIT} PARENT_SCOPE)
            set(HASH ${GIT_HASH} PARENT_SCOPE)
            set(ALL_GIT_COMMIT_COUNT ${ALL_GIT_COMMIT_COUNT} PARENT_SCOPE)

    endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.git)

    if(EXISTS ${PROJECT_BINARY_DIR}/Authors.txt)
        file(READ ${PROJECT_BINARY_DIR}/Authors.txt GIT_AUTHORS)
    else(EXISTS ${PROJECT_BINARY_DIR}/Authors.txt)
        set(GIT_AUTHORS)
        execute_process(COMMAND "${GIT_EXECUTABLE}" log
            OUTPUT_VARIABLE GIT_LOG
            OUTPUT_STRIP_TRAILING_WHITESPACE
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

        string(REPLACE "\n" ";" GIT_LOG ${GIT_LOG})

        foreach(__line ${GIT_LOG})
            if(__line MATCHES "^Author:")
                string(REPLACE "Author: " "" __line "${__line}")
                string(REGEX REPLACE "[ ]?<.*" "" __line "${__line}")
                list(APPEND GIT_AUTHORS "${__line}")
          endif()
        endforeach()
        list(SORT GIT_AUTHORS)
        list(REMOVE_DUPLICATES GIT_AUTHORS)
        file(WRITE ${PROJECT_BINARY_DIR}/Authors.txt "${GIT_AUTHORS}")
    endif(EXISTS ${PROJECT_BINARY_DIR}/Authors.txt)
endfunction(getGitInfo)  

  
function(generateGitInfo)
    if(EXISTS ${CMAKE_SOURCE_DIR}/.git)
        set(GIT_EXECUTABLE "git")
        add_custom_command(OUTPUT ${SRCDIR}/gitrevision.hh
            COMMAND ${CMAKE_COMMAND} -E echo_append "#define GITREVISION " > ${SRCDIR}/gitrevision.hh
            COMMAND ${GIT_SCM} log -1 "--pretty=format:%h %ai" >> ${SRCDIR}/gitrevision.hh
            DEPENDS ${GITDIR}/logs/HEAD
            VERBATIM
        )
    endif(EXISTS ${CMAKE_SOURCE_DIR}/.git)
endfunction(generateGitInfo)

function(targetName flag)
    if(${flag})
        if(NOT TARGET targetName)
            add_custom_target(targetName
                COMMENT "Running targetName ."
            )
        endif()
    endif(${flag})
endfunction(targetName)


