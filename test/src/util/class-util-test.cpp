#include "class-util-test.hpp"
#include "test-util/data.hpp"
#include "util/class-util.hpp"
#include <gtest/gtest.h>

TEST(ClassUtilSuite, instanceof) {
  A a;
  B b;
  C<int> ci;
  C<Data> cd;
  C<void> cv;
  D d;
  E e;

  EXPECT_TRUE(instanceof <A>(&b));
  EXPECT_FALSE(instanceof <B>(&a));

  EXPECT_TRUE(instanceof <B>(&ci));
  EXPECT_TRUE(instanceof <A>(&ci));
  EXPECT_TRUE(instanceof <B>(&cd));
  EXPECT_TRUE(instanceof <A>(&cd));
  EXPECT_FALSE(instanceof <B>(&cv));
  EXPECT_TRUE(instanceof <A>(&cv));

  EXPECT_TRUE(instanceof <C<int>>(&d));
  EXPECT_FALSE(instanceof <C<void>>(&d));
  EXPECT_TRUE(instanceof <C<void>>(&e));
  EXPECT_FALSE(instanceof <C<int>>(&e));
}
