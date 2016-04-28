
INCLUDE_DIRECTORIES( ${LIBCCCC_SOURCE_DIR}/include )

add_executable( example0 main.cc )

target_link_libraries( example0 cccc )
