cmake_minimum_required(VERSION 3.23)
project(Competitive_Coding)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(. DIR_SRCS)

add_subdirectory(Codeforces)

add_executable(Competitive_Coding main.cpp)
target_link_libraries(Competitive_Coding Codeforces)