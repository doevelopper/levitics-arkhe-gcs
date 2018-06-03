#       levitics-arkhe-gcs/src/main/resources/config/macros/macros.cmake
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

find_package(APR)
find_package(APR-UTIL)

if(APR_FOUND AND APRU_FOUND)

    find_library(LOG4CXX_LIBRARY 
        NAMES 
            liblog4cxx.a log4cxx.a
        HINTS 
	    /home/happyman/gcs_installs/lib/
            /usr/local/lib/ 
            /usr/lib/ 
	    /usr/lib/x86_64-linux-gnu
	    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    )

    find_path(LOG4CXX_INCLUDE_DIR 
        NAMES 
            log4cxx/log4cxx.h
        HINTS 
            /home/happyman/gcs_installs/include
            /usr/local/include
            /usr/include 
            ${CMAKE_INSTALL_INCLUDEDIR}
   )

#   message(STATUS "LOG4CXX_LIBRARY ${LOG4CXX_LIBRARY}")
#   message(STATUS "LOG4CXX_INCLUDE_DIR ${LOG4CXX_INCLUDE_DIR}")

   include(FindPackageHandleStandardArgs)
   find_package_handle_standard_args(log4cxx
       REQUIRED_VARS LOG4CXX_LIBRARY  LOG4CXX_INCLUDE_DIR
   )
set(LOG4CXX_DEFINITIONS "HAVE_LOG4CXX")
   if(LOG4CXX_FOUND)

      set(LOG4CXX_LIBRARIES ${LOG4CXX_LIBRARY})
      set(LOG4CXX_INCLUDE_DIRS ${LOG4CXX_INCLUDE_DIR} ${APR_INCLUDES})

      if(NOT TARGET LOG4CXX::LOG4CXX)
          add_library(LOG4CXX::LOG4CXX UNKNOWN IMPORTED)
          set_target_properties(LOG4CXX::LOG4CXX PROPERTIES
	      INTERFACE_COMPILE_DEFINITIONS "${LOG4CXX_DEFINITIONS}"
              IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
              IMPORTED_LOCATION "${LOG4CXX_LIBRARY}"
	      INTERFACE_INCLUDE_DIRECTORIES "${LOG4CXX_INCLUDE_DIRS}"
	      INTERFACE_LINK_LIBRARIES ${APR_LIBRARY};${EXPAT_LIBRARY};${APRUTIL_LIBRARY})
      endif(NOT TARGET LOG4CXX::LOG4CXX)

   endif(LOG4CXX_FOUND)

   include(FindPackageHandleStandardArgs)
   find_package_handle_standard_args(LOG4CXX
         REQUIRED_VARS LOG4CXX_LIBRARY LOG4CXX_INCLUDE_DIR
	 #VERSION_VAR LOG4CXX_VERSION_STRING
    )

else (APR_FOUND AND APRU_FOUND)
    message(FATAL_ERROR "Could not find APR/Expat/APRu library")
endif(APR_FOUND AND APRU_FOUND)

mark_as_advanced(LOG4CXX_INCLUDE_DIR LOG4CXX_LIBRARY)

