set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../bin)
include_directories(src)
add_library(${lib}
	src/data/actor.cpp
	src/data/command.cpp
	src/data/converter.cpp
	src/data/help.cpp
	src/data/key.cpp
	src/data/rune.cpp
	src/data/settings.cpp
	src/util/arg-parser.cpp
	src/util/binary-util.cpp
	src/util/color.cpp
	src/util/file-util.cpp
	src/util/password-util.cpp
)
