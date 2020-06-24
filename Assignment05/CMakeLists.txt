cmake_minimum_required(VERSION 3.16)
project(AlgorithmAssignment C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FILES headers/fibo.h src/fibo.c src/knapsack.c headers/knapsack.h headers/matrix.h src/matrix.c headers/utils.h src/utils.c main.c)

add_executable(AlgorithmAssignment ${SOURCE_FILES})