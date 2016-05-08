
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(CCCC_TEST)

include_directories( ${LIBCCCC_SOURCE_DIR}/include )
include_directories( ${CCCC_TEST_SOURCE_DIR}/Catch/single_include )

# assuming target "my_prog" exists
if( WITH_PROF)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage") # debug, no optimisation
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage") # debug, no optimisation
	SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lgcov" )
	message( "Setting up Profiling and Code Coverage" )
endif()
#

set( DEPS "${DEPS};cccc" )

file ( GLOB_RECURSE TEST_CPP ./*.cc )

add_executable( cccc_test ${TEST_CPP} )

target_link_libraries( cccc_test ${DEPS} )

