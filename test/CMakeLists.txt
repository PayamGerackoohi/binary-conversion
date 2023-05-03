set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
include_directories(src)
add_executable(${test}
	src/main.cpp
	src/data/actor-test.cpp
	src/data/command-test.cpp
	src/data/converter-test.cpp
	src/data/key-test.cpp
	src/data/rune-test.cpp
	src/data/settings-test.cpp
	src/test-util/data.cpp
	src/util/arg-parser-test.cpp
	src/util/binary-util-test.cpp
	src/util/class-util-test.cpp
	src/util/file-util-test.cpp
	src/util/password-util-test.cpp
)

set(GTEST_INSTALLDIR "/usr/local/googletest")
target_include_directories(${test} PRIVATE ${GTEST_INSTALLDIR}/googletest/include)
target_link_directories(${test} PRIVATE ${GTEST_INSTALLDIR}/lib)
target_link_libraries(${test} PRIVATE gtest)

target_include_directories(${test} PRIVATE ../library/src)
target_link_libraries(${test} PRIVATE ${lib})
