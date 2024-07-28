set(src_dir "src")
set(srcs "${src_dir}/main.cpp")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${srcs})
target_link_libraries(${PROJECT_NAME} PRIVATE mylib::mylib)