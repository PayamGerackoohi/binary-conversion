set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
include_directories(src)
add_executable(${pn}
	src/main.cpp
)
target_include_directories(${pn} PRIVATE ../library/src)
target_link_libraries(${pn} PRIVATE ${lib})
