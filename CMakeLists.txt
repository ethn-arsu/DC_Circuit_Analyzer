cmake_minimum_required(VERSION 3.28)

project(DC_Circuit_Analyzer C)

set(CMAKE_C_STANDARD 23)


include_directories(include)


add_executable(
        DC_Circuit_Analyzer

        src/main.c
        src/circuit.c
        include/resistor.h
        include/solver.h
        src/resistor.c
        src/solver.c
        test/testCircuit.c
)