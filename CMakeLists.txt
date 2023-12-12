cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(BinaryConversion VERSION 1.0.0)
message(STATUS "ProjectVersion = ${CMAKE_PROJECT_VERSION}")
add_compile_definitions(VERSION="${CMAKE_PROJECT_VERSION}")

set(libraryName binary-conversion)
add_subdirectory(library)
add_subdirectory(module)
add_subdirectory(test)
