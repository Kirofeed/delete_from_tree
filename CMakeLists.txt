cmake_minimum_required(VERSION 3.5.0)
project(create_tree VERSION 0.1.0 LANGUAGES C CXX)

add_compile_options(-Wall -Wextra -Werror)

add_executable(create_tree main.cpp)
