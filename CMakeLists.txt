set(pn binary-conversion)
# set(lib ${pn}-lib)
set(lib bc)
set(test ${pn}-test)
project(${pn})

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BuildModule "Build Module" ON)
option(BuildTest "Build Test" OFF)

add_subdirectory(library)

if(BuildModule)
	add_subdirectory(module)
endif(BuildModule)

if(BuildTest)
	add_subdirectory(test)
endif(BuildTest)
