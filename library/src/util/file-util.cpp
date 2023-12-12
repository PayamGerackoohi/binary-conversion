#include "util/file-util.hpp"
#include <sys/stat.h>

bool exists(std::string file) {
  struct stat buffer;
  return stat(file.c_str(), &buffer) == 0;
}
