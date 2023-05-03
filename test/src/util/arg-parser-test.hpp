#ifndef ARG_PARSER_TEST_HPP
#define ARG_PARSER_TEST_HPP

#include "data/actor.hpp"
#include "util/arg-parser.hpp"

class Info : public Actor<void> {
  void action() override;
};

class TestSettings {
public:
  enum Arg { Default, Help, Version, Info, Input, Size };
  std::string input;
  int size;

  TestSettings();
  void reset();
  int diff(int flag);
  void add(int);

private:
  int flag;
};

void showVersion();

void testArgs(ArgParser &, std::vector<const char *>, int flag);

#endif
