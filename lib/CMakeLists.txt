cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(LIBCCCC CXX)

# Set custom cmake scripts directory
# set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LIBCCCC_SOURCE_DIR}/cmake")

# Add Dynamic Library Loader dependency, pthread, uuid (if UNIX-based)
if( ${CCCC_CURRENT_SYSTEM} STREQUAL "LINUX" )
    set( DEPS "${DEPS};dl" )
    set( DEPS "${DEPS};pthread" )
endif()

# Lua
# find_package( LuaJIT )
# if( LUAJIT_FOUND )
# message("Found LuaJIT")
# include_directories( ${LUAJIT_INCLUDE_DIR} )
# TODO: Replace hardcoded lua lib linkage with automated one
# set( DEPS "${DEPS};${LUAJIT_LIBRARIES}" )
# endif()

# Set include directories
include_directories( ${LIBCCCC_SOURCE_DIR}/include )

# Make headers appear in QtCreator
FILE(GLOB_RECURSE HeaderFiles "include/*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

file ( GLOB_RECURSE CORE_CPP ./src/*.cc )
set( LIBCCCC_CPP ${CORE_CPP} )
if( ${CCCC_CURRENT_SYSTEM} STREQUAL "WINDOWS" )
  add_library( cccc ${LIBCCCC_CPP} )
else()
  add_library( cccc SHARED ${LIBCCCC_CPP} )
endif()

# Link libraries
target_link_libraries( cccc ${DEPS} )
