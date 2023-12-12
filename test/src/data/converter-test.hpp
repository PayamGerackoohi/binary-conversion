#ifndef CONVERTER_TEST_HPP
#define CONVERTER_TEST_HPP

#include "data/converter.hpp"
#include "data/settings.hpp"
#include <memory>
#include <string>
#include <vector>

std::unique_ptr<Converter> setup(Settings *);
void cleanup();
void makeData();
void checkRecoveredFile(const std::string fileName);
void checkOutput(const std::string fileName, const std::vector<char> &bytes);

#endif
