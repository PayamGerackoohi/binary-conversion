#include "file-util-test.hpp"
#include "util/file-util.hpp"
#include <gtest/gtest.h>
#include <string>

const std::string VALID_FILE = "data/in.txt";
const std::string INVALID_FILE = "data/in2.txt";

TEST(FileUtilSuite, exists) {
  EXPECT_TRUE(exists(VALID_FILE));
  EXPECT_FALSE(exists(INVALID_FILE));
}
