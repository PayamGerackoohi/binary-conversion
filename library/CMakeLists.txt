include_directories(include)
file(GLOB sources
	src/data/*.cpp
	src/util/*.cpp
)
add_library(${libraryName} ${sources})
