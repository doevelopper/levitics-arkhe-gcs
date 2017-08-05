find_program(APU_CONFIG_EXECUTABLE apu-1-config
             PATHS /usr/local/apr/bin
            ${TARGET_BUILD_DIRECTORY}/bin 
)
mark_as_advanced(APU_CONFIG_EXECUTABLE)
#message(STATUS "APU_CONFIG_EXECUTABLE ${APU_CONFIG_EXECUTABLE}")

macro(_apu_invoke _varname _regexp)
    execute_process(
        COMMAND ${APU_CONFIG_EXECUTABLE} ${ARGN}
        OUTPUT_VARIABLE _apu_output
        RESULT_VARIABLE _apu_failed
    )

    if(_apu_failed)
        message(FATAL_ERROR "${APU_CONFIG_EXECUTABLE} ${ARGN} failed")
    else()
        string(REGEX REPLACE "[\r\n]"  "" _apu_output "${_apu_output}")
        string(REGEX REPLACE " +$"     "" _apu_output "${_apu_output}")

        if(NOT ${_regexp} STREQUAL "")
            string(REGEX REPLACE "${_regexp}" " " _apu_output "${_apu_output}")
        endif()

        # XXX: We don't want to invoke separate_arguments() for APU_LDFLAGS;
        # just leave as-is
        if(NOT ${_varname} STREQUAL "APU_LDFLAGS")
            separate_arguments(_apu_output)
        endif()

        set(${_varname} "${_apu_output}")
    endif()
endmacro(_apu_invoke)

_apu_invoke(APU_INCLUDES  "(^| )-I" --includes)
_apu_invoke(APU_EXTRALIBS "(^| )-l" --libs)
_apu_invoke(APU_LIBS      ""        --link-ld)
_apu_invoke(APU_LDFLAGS   ""        --ldflags)
_apu_invoke(APU_VERSION   ""        --version)

#message(STATUS "APU_INCLUDES ${APU_INCLUDES}")
#message(STATUS "APU_EXTRALIBS ${APU_EXTRALIBS}")
#message(STATUS "APU_LIBS ${APU_LIBS}")
#message(STATUS "APU_LDFLAGS ${APU_LDFLAGS}")
#message(STATUS "APU_VERSION ${APU_VERSION}")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(APU DEFAULT_MSG APU_INCLUDES APU_LIBS APU_VERSION)

