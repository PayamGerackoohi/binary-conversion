#include "rune-test.hpp"
#include "data/rune.hpp"
#include <gtest/gtest.h>

TEST(RuneSuite, gen) {
  Rune rune("123");
  for (int i = 0; i < 30; i++) {
    EXPECT_EQ(rune.gen(), '1');
    EXPECT_EQ(rune.gen(), '2');
    EXPECT_EQ(rune.gen(), '3');
  }
}
