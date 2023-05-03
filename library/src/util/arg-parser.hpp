#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include "../data/key.hpp"
#include "util/color.hpp"
#include <iostream>

class ArgParser {
public:
  ArgParser();
  void parse(int argc, const char **argv);
  void addKey(std::unique_ptr<BaseKey> &&key);
  void setDefault(std::function<void(void)> action);

private:
  std::vector<std::unique_ptr<BaseKey>> keys;
  std::function<void(void)> defaultAction;
  int argc;
  const char **argv;
  std::string arg;

  void parseArg(int &index);
  BaseKey *findKeyBy(std::string arg);
  void handleArg(int &index, BaseKey *);
  inline void voidKey(Key<void> *);
  inline void stringKey(Key<std::string> *, int &index);
  inline void intKey(Key<int> *, int &index);
  template <typename T> void handleKey(Key<T> *key, int &i, std::function<T(std::string)> converter);
};

#include "arg-parser.tpp"

#endif
