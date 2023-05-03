#include "arg-parser-test.hpp"
#include <gtest/gtest.h>
#include <initializer_list>
#include <memory>
#include <ostream>
#include <vector>

using std::string;

TestSettings settings;

TEST(ArgParserTestSuite, parse) {
  ArgParser parser;
  using args = std::initializer_list<std::string>;
  parser.setDefault([]() { settings.add(TestSettings::Arg::Default); });
  parser.addKey(std::make_unique<Key<void>>(args{"h", "help"}, [&]() { settings.add(TestSettings::Arg::Help); }));
  parser.addKey(std::make_unique<Key<void>>(args{"v", "version"}, showVersion));
  parser.addKey(std::make_unique<Key<void>>(args{"--info"}, Info()));
  parser.addKey(std::make_unique<Key<string>>(args{"-i", "--input"}, [&](string s) {
    settings.add(TestSettings::Arg::Input);
    settings.input = s;
  }));
  parser.addKey(std::make_unique<Key<int>>(args{"-s", "--size"}, [&](int i) {
    settings.add(TestSettings::Arg::Size);
    settings.size = i;
  }));

  testArgs(parser, {}, 1);

  testArgs(parser, {"h"}, 0b10);

  testArgs(parser, {"v"}, 0b100);

  testArgs(parser, {"h", "v"}, 0b110);

  testArgs(parser, {"h", "v", "--info"}, 0b1110);

  testArgs(parser, {"h", "v", "--info", "-i", "asdf"}, 0b11110);
  EXPECT_EQ(settings.input, "asdf");

  testArgs(parser, {"h", "v", "--info", "-i", "asdf", "--size", "123"}, 0b111110);
  EXPECT_EQ(settings.input, "asdf");
  EXPECT_EQ(settings.size, 123);
}

void testArgs(ArgParser &parser, std::vector<const char *> list, int flag) {
  settings.reset();
  list.emplace(list.begin(), "");
  parser.parse(list.size(), list.data());
  EXPECT_EQ(settings.diff(flag), 0);
}

TestSettings::TestSettings() { reset(); }

int TestSettings::diff(int flag) { return this->flag ^ flag; }

void TestSettings::reset() {
  flag = 0;
  input = "";
  size = 0;
}

void TestSettings::add(int i) { flag |= (1 << i); }

void showVersion() { settings.add(TestSettings::Arg::Version); }

void Info::action() { settings.add(TestSettings::Arg::Info); }
