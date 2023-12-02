cmake_minimum_required(VERSION 3.26)
project(3D_Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-DDEBUG")

add_subdirectory(lib)
add_subdirectory(game)
