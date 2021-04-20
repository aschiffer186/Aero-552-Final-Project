cmake_minimum_required(VERSION 2.8)
project(FINAL_PROJECT)

set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED True)
add_compile_options(-std=c++11)

add_subdirectory(src)

add_subdirectory(tests)

add_executable(Final_Project src/main)
target_include_directories(Final_Project PRIVATE ${FINAL_PROJECT_SOURCE_DIR}/include/)
target_link_libraries(Final_Project PRIVATE Compiler)