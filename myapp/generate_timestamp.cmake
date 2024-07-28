# Get the current timestamp
string(TIMESTAMP today "%Y%m%d%H%M%S")

configure_file(${CMAKE_CURRENT_LIST_DIR}/timestamp.h.in timestamp.h @ONLY)
