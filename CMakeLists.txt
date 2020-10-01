cmake_minimum_required(VERSION 2.6)
project(ENGINE)

include_directories(
src
)

add_executable(demo 
src/demo/main.cpp
)

target_link_libraries(demo engine)

add_library(engine SHARED
src/engine/Core.cpp
src/engine/Core.h
)