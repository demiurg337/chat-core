cmake_minimum_required(VERSION 3.10)
project(chat)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

include_directories("${CMAKE_SOURCE_DIR}/src")
add_executable(chat src/log.c src/network.c src/utils.c src/friends.c src/main.c)
