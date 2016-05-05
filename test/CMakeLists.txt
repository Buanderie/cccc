
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(CCCC_TEST)

include_directories( ${LIBCCCC_SOURCE_DIR}/include )
include_directories( ${CCCC_TEST_SOURCE_DIR}/Catch/single_include )

set( DEPS "${DEPS};cccc" )

file ( GLOB_RECURSE TEST_CPP ./*.cc )

add_executable( cccc_test ${TEST_CPP} )

target_link_libraries( cccc_test ${DEPS} )
