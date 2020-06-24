cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 11)
set(SOURCE_FIlES main.c headers/LCS.h src/LCS.c headers/utils.h src/utils.c headers/bfs.h src/bfs.c headers/graph.h src/graph.c headers/dijkstra.h src/dijkstra.c)

add_executable(main ${SOURCE_FIlES})