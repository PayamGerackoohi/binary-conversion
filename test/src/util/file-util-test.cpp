#include "file-util-test.hpp"
#include "util/file-util.hpp"
#include <gtest/gtest.h>
#include <string>

const std::string VALID_FILE = "test/src/util/file-util-test.hpp";
const std::string INVALID_FILE = VALID_FILE + "2";

TEST(FileUtilSuite, exists) {
  EXPECT_TRUE(exists(VALID_FILE));
  EXPECT_FALSE(exists(INVALID_FILE));
}
