cmake_minimum_required(VERSION 3.16)
project(hash_generatorius)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_generatorius main.cpp converter.h IO.cpp IO.h converter.cpp Tests.h Tests.cpp)
