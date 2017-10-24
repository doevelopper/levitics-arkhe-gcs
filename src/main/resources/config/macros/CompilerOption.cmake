include(CMakeParseArguments)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS                           OFF) ## on g++ this ensures: -std=c++XX and not -std=gnu++XX
set(CXX_STANDARD_REQUIRED                          ON)
set(CMAKE_CXX_FLAGS                                "${CMAKE_CXX_FLAGS} -std=c++17 -W -Wall -Wextra ")
set(CMAKE_CXX_FLAGS_DEBUG                          "${CMAKE_CXX_FLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS_DEBUG                          "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -D_FORTIFY_SOURCE=2 ")
set(CMAKE_CXX_FLAGS_DEBUG                          "${CMAKE_CXX_FLAGS_DEBUG} -fno-strict-aliasing -fno-omit-frame-pointer ")
set(CMAKE_CXX_FLAGS_MINSIZEREL                     "${CMAKE_CXX_FLAGS} -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE                        "${CMAKE_CXX_FLAGS} -O4 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO                 "${CMAKE_CXX_FLAGS} -O2 -g")

set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wabi")
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wcast-qual")                # Cast for removing type qualifiers
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wconversion")               # Implicit conversions that may alter a value
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wfloat-equal")              # Floating values used in equality comparisons
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Winline")                   # If a inline declared function couldn't be inlined
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wmissing-declarations")     # If a global function is defined without a previous declaration
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wmissing-format-attribute") #
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Woverloaded-virtual")       # when a function declaration hides virtual functions from a base class
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wpacked")                   #
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wredundant-decls")          # if anything is declared more than once in the same scope
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wshadow")                   # whenever a local variable or type declaration shadows another one
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wsign-promo")               #
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wno-missing-field-initializers")
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wno-missing-braces")
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -Wno-sign-compare")
set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fdiagnostics-show-option")

if(CHECK_MEMORY)
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize=memory")
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize-memory-track-origins=2")
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fno-omit-frame-pointer")
elseif(CHECK_ADDRESS)
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize=address")
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fno-omit-frame-pointer")
elseif(CHECK_THREAD)
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize=thread")
endif()

if(CHECK_UNDEFINED)
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize=undefined-trap")
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize-undefined-trap-on-error")
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fno-sanitize-recover")
endif()

if(CHECK_DATAFLOW)
   set(EXTRA_CXX_FLAGS "${EXTRA_CXX_FLAGS} -fsanitize=dataflow")
endif()

set(EFFECTIVE_CPP_FLAGS "-Weffc++ -Wpedantic")

set(PARANO_CMAKE_CXX_FLAGS )
if(WERROR_LEVEL_1)
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=format-security -Wformat")
	# set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=old-style-cast")
	# set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=shadow")
elseif(WERROR_LEVEL_2)
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=return-type")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=format-security -Wformat")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=old-style-cast")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=return-type -Werror=shadow")
	set(PARANO_CMAKE_CXX_FLAGS "${COMMON_CMAKE_CXX_FLAGS} -Werror -pedantic")
	set(PARANO_CMAKE_CXX_FLAGS "${COMMON_CMAKE_CXX_FLAGS} -Werror=switch-default -Werror=unused-result")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=implicit-function-declaration")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point")
	set(PARANO_CMAKE_CXX_FLAGS "${PARANO_CMAKE_CXX_FLAGS} -Werror=unused-result")
endif()



#if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wmissing-format-attribute -Wwrite-strings")
#    #set(CMAKE_C_FLAGS "${PARANO_CMAKE_CXX_FLAGS}")
#endif()
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}                            ${COMMON_CMAKE_CXX_FLAGS} ")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}                                        ${COMMON_CMAKE_CXX_FLAGS} ")
#set(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG}                         -O0 --coverage")
#set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}                        -Wall -Wextra")



set(GCC_COMMON_WARNING_FLAGS "-Wcast-align -Wchar-subscripts")
set(GCC_COMMON_WARNING_FLAGS "-Wformat-security ")
set(GCC_COMMON_WARNING_FLAGS "-Wshadow -Wunused-variable  -Wunused-parameter")
set(GCC_COMMON_WARNING_FLAGS "-Wpointer-arith -Wundef -Wdelete-non-virtual-dtor -Wzero-as-null-pointer-constant" )
set(GCC_COMMON_WARNING_FLAGS "-Wunused-function -Wunused -Wno-system-headers")
set(GCC_COMMON_WARNING_FLAGS "-Wno-deprecated -Wwrite-strings")
set(GCC_COMMON_WARNING_FLAGS "-Wconversion -D_FORTIFY_SOURCE=2 -Wsign-conversion -fstack-protector-all")
set(GCC_COMMON_WARNING_FLAGS "-Wstack-protector --param ssp-buffer-size=4")


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wnon-virtual-dtor -Woverloaded-virtual")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wno-long-long -Wformat")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMMON_WARNING_FLAGS} -Wfloat-equal -Wdisabled-optimization")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PARANO_CMAKE_CXX_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}                        ${COMMON_CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}                    ${COMMON_CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}                                    ${COMMON_CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG}                     -fprofile-arcs -ftest-coverage --coverage")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG}       --coverage")#-lgcov



# foreach(compilerFeatures ${CMAKE_CXX_COMPILE_FEATURES})
    # message("compile Feature ${compilerFeatures}")
# endforeach()

# get_property(known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)
# foreach(i ${known_features})
    # message("Known compile feature ${i}")
# endforeach()
