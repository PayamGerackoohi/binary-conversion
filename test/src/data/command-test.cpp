#include "command-test.hpp"
#include "data/command.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(CommandSuite, toString) {
  EXPECT_STREQ(toString(Command::None).c_str(), "None");
  EXPECT_STREQ(toString(Command::Convert).c_str(), "Convert");
}

TEST(CommandSuite, stream) {
  std::stringstream ss;
  ss << Command::Convert;
  EXPECT_STREQ(ss.str().c_str(), "Convert");
}
