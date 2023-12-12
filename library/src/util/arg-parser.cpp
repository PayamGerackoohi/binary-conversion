#include "util/arg-parser.hpp"

#define isKey(TYPE)                                                                                \
  auto key = dynamic_cast<Key<TYPE> *>(baseKey);                                                   \
  key != nullptr

using std::cerr;
using std::endl;
using std::function;
using std::string;
using std::unique_ptr;

ArgParser::ArgParser() : defaultAction([]() {}) {}

void ArgParser::parse(int argc, const char **argv) {
  this->argc = argc;
  this->argv = argv;
  if (argc == 1)
    defaultAction();
  else
    for (int index = 1; index < argc; index++)
      parseArg(index);
}

void ArgParser::parseArg(int &i) {
  arg = argv[i];
  auto key = findKeyBy(arg);
  if (key == nullptr) {
    cerr << payam::red << "Invalid argument: '" << arg << "'" << endl;
    exit(1);
  } else
    handleArg(i, key);
}

BaseKey *ArgParser::findKeyBy(string arg) {
  auto index = find_if(keys.begin(), keys.end(), [&](unique_ptr<BaseKey> &key) {
    auto args = &key.get()->keys;
    return find(args->begin(), args->end(), arg) != args->end();
  });
  if (index == keys.end())
    return nullptr;
  else
    return index->get();
}

void ArgParser::handleArg(int &i, BaseKey *baseKey) {
  if (isKey(void))
    voidKey(key);
  else if (isKey(string))
    stringKey(key, i);
  else if (isKey(int))
    intKey(key, i);
  else {
    cerr << payam::red << "Unknown key type!" << endl;
    exit(1);
  }
}

void ArgParser::addKey(unique_ptr<BaseKey> &&key) { keys.emplace_back(move(key)); }

void ArgParser::setDefault(function<void(void)> action) { defaultAction = action; }

void ArgParser::voidKey(Key<void> *key) { key->action(); }

void ArgParser::stringKey(Key<string> *key, int &i) {
  handleKey<string>(key, i, [](std::string s) { return s; });
}

void ArgParser::intKey(Key<int> *key, int &i) {
  handleKey<int>(key, i, [](string s) { return std::stoi(s); });
}
