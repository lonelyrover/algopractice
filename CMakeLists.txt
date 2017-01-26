cmake_minimum_required(VERSION 3.0)
project(festival)

set(SOURCE festival.cpp)

add_executable(${PROJECT_NAME}.exe $(SOURCE))