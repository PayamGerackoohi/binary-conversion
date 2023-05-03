#include "password-util-test.hpp"
#include "util/password-util.hpp"
#include <gtest/gtest.h>

// std::string expandPassword(Settings *settings);

TEST(PasswordUtilSuite, expandPassword) {
  Settings settings;
  EXPECT_EQ(expandPassword(&settings), "3174449;9:");

  settings.password = "abcd";
  settings.expandedPasswordSize = 20;
  EXPECT_EQ(expandPassword(&settings), "cagagekmkioiomsusqwq");

  settings.password = "z82;.";
  settings.expandedPasswordSize = 30;
  EXPECT_EQ(expandPassword(&settings), "x;6>(}0;1%v5<4>k*!/;l/*\"4a$/%1");
}
