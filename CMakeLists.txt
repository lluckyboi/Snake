cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 14)

#引入easyX
link_libraries(libeasyx.a)

add_executable(
        snake
        main.cpp
)
