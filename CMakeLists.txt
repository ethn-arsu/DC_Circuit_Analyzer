cmake_minimum_required(VERSION 4.3)
project(DC_Circuit_Analyzer C)

set(CMAKE_C_STANDARD 23)

add_executable(DC_Circuit_Analyzer src/main.c
        src/circuit.c
        include/circuit.h)
