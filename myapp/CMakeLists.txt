set(src_dir "src")
set(srcs "${src_dir}/main.cpp")

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${srcs})
target_link_libraries(${PROJECT_NAME} PRIVATE mylib::mylib)

target_compile_definitions(
  ${PROJECT_NAME} PRIVATE VERSION_MAJOR="${${PROJECT_NAME}_VERSION_MAJOR}")
target_compile_definitions(
  ${PROJECT_NAME} PRIVATE VERSION_MINOR="${${PROJECT_NAME}_VERSION_MINOR}")

if(use_timestamp)
  target_include_directories(${PROJECT_NAME}
                             PRIVATE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}")
  add_custom_target(
    generate_timestamp ALL
    COMMAND ${CMAKE_COMMAND} -P
            ${CMAKE_CURRENT_LIST_DIR}/generate_timestamp.cmake
    COMMENT "Generating
  timestamp")
  add_dependencies(${PROJECT_NAME} generate_timestamp)
else()
  target_compile_definitions(${PROJECT_NAME} PRIVATE TIMESTAMP="0")
endif()
