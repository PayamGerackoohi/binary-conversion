template <typename T> void ArgParser::handleKey(Key<T> *key, int &i, std::function<T(std::string)> converter) {
  if (++i < argc) {
    auto next = argv[i];
    key->action(converter(next));
  } else {
    std::cerr << payam::red << "No value is passed for the argument: '" << arg << "'" << std::endl;
    exit(1);
  }
}
