#include "data/converter.hpp"
#include "data/rune.hpp"
#include "util/binary-util.hpp"
#include "util/color.hpp"
#include "util/password-util.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <istream>
#include <memory>
#include <sstream>

using std::cerr;
using std::cout;
using std::endl;
using std::flush;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::stringstream;

Converter::Converter(Settings *settings) : settings(settings) {}

void Converter::convert() {
  if (settings->hasValidIO())
    doConversion(settings->input, settings->output);
  else {
    cerr << payam::red << "Invalid IO" << endl;
    exit(1);
  }
}

void Converter::show(Size processed, Size size) {
  stringstream ss;
  int percentage = static_cast<int>(100 * processed / size);
  int p = percentage / 2;
  for (int i = 0; i < p; i++)
    ss << '#';
  for (int i = p; i < 50; i++)
    ss << '-';
  cout << "\r[" << ss.str() << "] " << percentage << "% (" << format(processed) << "/"
       << format(size) << ")" << flush;
}

void Converter::doConversion(const string &inputFile, const string &outputFile) {
  auto inputMode = ios::binary;
  auto outputMode = inputMode;
  if (inputFile == outputFile) {
    inputMode |= ios::in | ios::out;
    outputMode = inputMode;
  }
  ifstream input(inputFile, inputMode);
  ofstream output(outputFile, outputMode);

  input.seekg(0, input.end);
  Size size = static_cast<Size>(input.tellg());
  Size remained = size;
  input.seekg(0, input.beg);
  Size chunkSize = std::min(std::max(1ull, size / 100ull), MAX_CHUNK_SIZE);
  auto p = expandPassword(settings);
  Rune rune(p);

  auto buffer = std::make_unique<char[]>(MAX_CHUNK_SIZE);
  int index = 1;
  while (remained > 0) {
    Size step = chunkSize;
    if (remained < chunkSize)
      step = remained;
    input.seekg(size - remained);
    input.read(buffer.get(), step);
    for (int i = 0; i < step; i++)
      buffer[i] = rune.gen() ^ buffer[i];
    output.seekp(size - remained);
    output.write(buffer.get(), step);
    remained -= step;
    show(size - remained, size);
  }
  input.close();
  output.close();
  cout << endl;
}
