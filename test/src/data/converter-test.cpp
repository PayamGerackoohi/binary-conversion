#include "converter-test.hpp"
#include "gtest/gtest-death-test.h"
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::make_unique;
using std::ofstream;
using std::pair;
using std::string;
using std::stringstream;
using std::unique_ptr;
using std::vector;
using std::filesystem::create_directory;

const string DATA_FOLDER = "data/";
const string INPUT_FILE = DATA_FOLDER + "in.txt";
const string OUTPUT_FILE = DATA_FOLDER + "out.txt";
const string INVALID_NAME = "as.df";
const pair<int, int> TABLE{3, 4};
const int PASSWORD_SIZE = 5;

#ifdef WIN_TEST
const vector<char> BYTES{0x02, 0x38, 0x05, 0x3d, 0x07, 0x3d, 0x0d, 0x32, 0x34, 0x30, 0x01,
                         0x38, 0x03, 0x3d, 0x02, 0x3d, 0x01, 0x32, 0x34, 0x30, 0x00, 0x38,
                         0x01, 0x3d, 0x0d, 0x3d, 0x08, 0x09, 0x30, 0x37, 0x39};
const vector<char> BYTES2{0x52, 0x79, 0x18, 0x68, 0x53, 0x6a, 0x44, 0x23, 0x6c, 0x6a, 0x51,
                          0x79, 0x1e, 0x68, 0x56, 0x6a, 0x48, 0x23, 0x6c, 0x6a, 0x50, 0x79,
                          0x1c, 0x68, 0x59, 0x6a, 0x41, 0x18, 0x68, 0x6d, 0x69};
#else
const vector<char> BYTES{0x02, 0x38, 0x05, 0x3d, 0x07, 0x3d, 0x0d, 0x32, 0x33, 0x08,
                         0x3a, 0x05, 0x3e, 0x02, 0x3d, 0x0c, 0x30, 0x31, 0x0a, 0x33,
                         0x05, 0x38, 0x0e, 0x3d, 0x05, 0x06, 0x30, 0x31};
const vector<char> BYTES2{0x52, 0x79, 0x18, 0x68, 0x53, 0x6a, 0x44, 0x23, 0x6b, 0x52,
                          0x6a, 0x44, 0x23, 0x57, 0x69, 0x5b, 0x79, 0x20, 0x52, 0x69,
                          0x55, 0x79, 0x13, 0x68, 0x51, 0x51, 0x79, 0x20};
#endif

TEST(ConverterSuite, overrideConversion) {
  Settings settings;
  settings.input = INPUT_FILE;
  auto converter = setup(&settings);

  converter->convert();
  checkOutput(INPUT_FILE, BYTES);

  converter->convert();
  checkRecoveredFile(INPUT_FILE);
}

TEST(ConverterSuite, outputCoversion) {
  Settings settings;
  settings.input = INPUT_FILE;
  settings.output = OUTPUT_FILE;
  auto converter = setup(&settings);

  converter->convert();
  checkOutput(OUTPUT_FILE, BYTES);

  settings.input = OUTPUT_FILE;
  converter->convert();
  checkRecoveredFile(OUTPUT_FILE);
}

TEST(ConverterSuite, missingInput) {
  Settings settings;
  settings.input = "";
  auto converter = setup(&settings);

  EXPECT_EXIT(converter->convert(), testing::ExitedWithCode(1), "Invalid IO");
}

TEST(ConverterSuite, invalidInput) {
  Settings settings;
  settings.input = INVALID_NAME;
  auto converter = setup(&settings);

  EXPECT_EXIT(converter->convert(), ::testing::ExitedWithCode(1), "Invalid IO");
}

TEST(ConverterSuite, customized) {
  Settings settings;
  settings.input = INPUT_FILE;
  settings.output = OUTPUT_FILE;
  settings.password = INVALID_NAME;
  settings.expandedPasswordSize = PASSWORD_SIZE;
  auto converter = setup(&settings);

  converter->convert();
  checkOutput(OUTPUT_FILE, BYTES2);

  settings.input = OUTPUT_FILE;
  converter->convert();
  checkRecoveredFile(OUTPUT_FILE);
}

unique_ptr<Converter> setup(Settings *settings) {
  cleanup();
  makeData();
  return make_unique<Converter>(settings);
}

void cleanup() { std::filesystem::remove_all(DATA_FOLDER); }

void makeData() {
  create_directory(DATA_FOLDER);
  ofstream file(INPUT_FILE);
  stringstream ss;
  for (int i = 1; i <= TABLE.first; i++) {
    for (int j = 1; j <= TABLE.second; j++)
      ss << i * j << '\t';
    ss << endl;
    file << ss.str();
    ss.str("");
  }
  file.close();
}

void checkRecoveredFile(const string fileName) {
  string line;
  ifstream recovered(fileName);
  getline(recovered, line);
  EXPECT_EQ(line, "1\t2\t3\t4\t");
  getline(recovered, line);
  EXPECT_EQ(line, "2\t4\t6\t8\t");
  getline(recovered, line);
  EXPECT_EQ(line, "3\t6\t9\t12\t");
  EXPECT_EQ(recovered.peek(), EOF);
  recovered.close();
}

void checkOutput(const string fileName, const vector<char> &bytes) {
  ifstream output(fileName, std::ios::binary);
  output.seekg(0, output.end);
  auto size = static_cast<unsigned long long>(output.tellg());
  output.seekg(0, output.beg);
  auto buffer = std::make_unique<char[]>(size);
  output.read(buffer.get(), size);
  output.close();
  EXPECT_EQ(size, bytes.size());
  for (int i = 0; i < size; i++)
    EXPECT_EQ(buffer[i], bytes[i]) << ", i: " << i;
}
/* Keep: to generate new 'BYTES' and 'BYTES2' vectors
cout << "const vector<char> BYTES{";
for (int i = 0; i < size; i++) {
        if (i != 0) cout << ", ";
        cout << "0x" << std::hex << std::setfill('0') << std::setw(2) << (int)buffer[i];
}
cout << "};" << endl;
*/
