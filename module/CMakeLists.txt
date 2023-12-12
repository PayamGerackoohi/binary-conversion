include_directories(src)
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ../library/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${libraryName})
