option(WIN_TEST "Configure the project for windows testing." OFF)
if(WIN_TEST)
	add_definitions(-DWIN_TEST)
endif(WIN_TEST)

set(testName ${PROJECT_NAME}Test)

file(GLOB sources
	src/*.cpp
	src/data/*.cpp
	src/util/*.cpp
	src/test-util/*.cpp
)
include_directories(src)
add_executable(${testName} ${sources})

set(GTEST_INSTALLDIR "gtest")
target_include_directories(${testName} PRIVATE ${GTEST_INSTALLDIR}/include)
target_link_directories(${testName} PRIVATE ${GTEST_INSTALLDIR}/lib)
target_link_libraries(${testName} PRIVATE gtest)
# set(GTEST_INSTALLDIR "/usr/local/googletest")
# target_include_directories(${testName} PRIVATE ${GTEST_INSTALLDIR}/googletest/include)

target_include_directories(${testName} PRIVATE ../library/include)
target_link_libraries(${testName} PRIVATE ${libraryName})

enable_testing()
add_test(UnitTests ${testName})
