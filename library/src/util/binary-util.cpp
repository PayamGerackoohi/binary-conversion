#include "util/binary-util.hpp"
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

vector<char> units{'k', 'M', 'G', 'T', 'P', 'E'};

inline string makeUnit(int index) { return string(" ") + units[index] + "B"; }

string format(unsigned long long bytes) {
  if (bytes < 1'000)
    return to_string(bytes) + " B";
  for (int i = 0; i < units.size(); i++)
    if (bytes < 1'000'000)
      return to_string(bytes / 1e3).substr(0, 5) + makeUnit(i);
    else
      bytes /= 1'000ull;
  return to_string(bytes) + makeUnit(static_cast<int>(units.size()) - 1);
}
