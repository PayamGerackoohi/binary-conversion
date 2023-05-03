#include "file-util.hpp"

bool exists(std::string file) {
  struct stat buffer;
  return stat(file.c_str(), &buffer) == 0;
}
