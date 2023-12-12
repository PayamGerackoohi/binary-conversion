#include "settings-test.hpp"
#include "data/command.hpp"
#include "data/settings.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

const string VALID_FILE = "data/in.txt";
const string INVALID_FILE1 = "as.df";
const string INVALID_FILE2 = "qw.er";
const string PASSWORD = "123";
const int EPS = 456;

TEST(SettingsSuite, hasValidIO) {
  Settings settings;
  EXPECT_FALSE(settings.hasValidIO());
  settings.input = VALID_FILE;
  EXPECT_TRUE(settings.hasValidIO());
  settings.input = INVALID_FILE1;
  EXPECT_FALSE(settings.hasValidIO());
}

TEST(SettingsSuite, ostream) {
  Settings settings;
  stringstream ss;
  ss << settings;
  EXPECT_EQ(ss.str(), "Settings<command<None> input<> output<> password<123> expandedPasswordSize<10>>");

  settings.command = Command::Convert;
  settings.input = INVALID_FILE1;
  settings.output = INVALID_FILE2;
  settings.password = PASSWORD;
  settings.expandedPasswordSize = EPS;
  ss.str("");
  ss << settings;
  EXPECT_EQ(ss.str(), "Settings<command<Convert> input<as.df> output<qw.er> password<123> expandedPasswordSize<456>>");
}
