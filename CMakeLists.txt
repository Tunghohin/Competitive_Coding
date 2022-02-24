cmake_minimum_required(VERSION 3.19)
project(Competitive_Coding)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. DIR_SRCS)

add_subdirectory(Daimayuan)

add_executable(Competitive_Coding main.cpp)

target_link_libraries(Competitive_Coding Daimayuan)

