cmake_minimum_required(VERSION 3.21)
project(jenish C)

set(CMAKE_C_STANDARD 99)

add_executable(jenish main.c parser/parsing.c)
