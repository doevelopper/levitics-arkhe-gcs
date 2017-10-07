
# set(cppsrc
    # gfs/hal/SystemInfo
 # )

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

# include_directories(${CMAKE_CURRENT_BINARY_DIR})

# add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})

# setup include directories 
# target_include_directories(${PROJECT_NAME}-osgi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# target_include_directories(${PROJECT_NAME}-osgi PUBLIC 
	# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
 	# $<INSTALL_INTERFACE:include>
# )

# setup export preprocessor definitions
# if(BUILD_SHARED_LIBS)
  # target_compile_definitions(${PROJECT_NAME}-osgi PRIVATE 	OSGI_EXPORTS) 
  # target_compile_definitions(${PROJECT_NAME}-osgi INTERFACE OSGI_IMPORTS) 
# endif()