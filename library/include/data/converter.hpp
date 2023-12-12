#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "settings.hpp"
#include <string>

class Converter {
public:
  Settings *settings;

  Converter(Settings *settings);
  void convert();

private:
  using Size = unsigned long long;
  const Size MAX_CHUNK_SIZE = 1'000'000;
  void doConversion(const std::string &inputFile, const std::string &outputFile);
  void show(Size processed, Size size);
};

#endif
