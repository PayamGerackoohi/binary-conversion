#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
// ::testing::GTEST_FLAG(filter) = "RuneSuite*";
// ::testing::GTEST_FLAG(filter) = "ConverterSuite.missingInput";
