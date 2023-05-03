#include "binary-util.hpp"
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

vector<char> units{'k', 'M', 'G', 'T', 'P', 'E'};

inline string makeUnit(int index) { return string(" ") + units[index] + "B"; }

string format(unsigned long long bytes) {
  if (bytes < 1000)
    return to_string(bytes) + " B";
  for (int i = 0; i < units.size(); i++)
    if (bytes < 1e6)
      return to_string(bytes / 1e3f).substr(0, 5) + makeUnit(i);
    else
      bytes /= 1e3;
  return to_string(bytes) + makeUnit(units.size() - 1);
}
