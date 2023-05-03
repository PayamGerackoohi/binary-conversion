#ifndef MAIN_HPP
#define MAIN_HPP

#include "data/settings.hpp"

void setConfig(int argc, const char **argv, Settings &);
void makeData();
void testConversion();
void convert(const std::string &sourceFile, const std::string &destinationFile);
void showVersion();
void convert(Settings *);
void checkCommands(Settings *);

#endif
