#include "util/binary-util.hpp"
#include <gtest/gtest.h>

TEST(BinaryUtilSuite, format) {
  std::string expectList[]{"1 B", "10 B", "100 B", "1.000 kB", "10.00 kB", "100.0 kB", "1.000 MB", "10.00 MB", "100.0 MB", "1.000 GB", "10.00 GB", "100.0 GB", "1.000 TB", "10.00 TB", "100.0 TB", "1.000 PB", "10.00 PB", "100.0 PB", "1.000 EB", "10.00 EB"};
  long long p = 1;
  for (int i = 0; i < 20; i++) {
    EXPECT_EQ(expectList[i], format(p));
    p *= 10;
  }
}
