#include "key-test.hpp"
#include "test-util/data.hpp"
#include <gtest/gtest.h>
#include <initializer_list>
#include <string>
#include <utility>
#include <vector>

using std::initializer_list;
using std::move;
using std::string;

initializer_list<string> list = {"a", "b", "c"};

TEST(KeySuite, baseKey) {
  BaseKey bk(move(list));
  checkKeys(bk);
}

TEST(KeySuite, voidKey) {
  bool b = false;
  Key<void> vk(move(list), [&]() { b = !b; });
  checkKeys(vk);
  vk.action();
  EXPECT_EQ(b, true);
  vk.action();
  EXPECT_EQ(b, false);
}

TEST(KeySuite, intKey) {
  int a;
  Key<int> ik(move(list), [&](int i) { a = i; });
  checkKeys(ik);
  EXPECT_EQ(ik.keys[0], "a");
  EXPECT_EQ(ik.keys[1], "b");
  EXPECT_EQ(ik.keys[2], "c");
  ik.action(1);
  EXPECT_EQ(a, 1);
  ik.action(2);
  EXPECT_EQ(a, 2);
}

TEST(KeySuite, DataKey) {
  Data data(1, "a");
  Key<Data> dk(move(list), [&](Data d) { data = std::move(d); });
  checkKeys(dk);
  EXPECT_EQ(dk.keys[0], "a");
  EXPECT_EQ(dk.keys[1], "b");
  EXPECT_EQ(dk.keys[2], "c");
  dk.action(Data(2, "b"));
  EXPECT_EQ(data.id, 2);
  EXPECT_EQ(data.value, "b");
  dk.action(Data(3, "c"));
  EXPECT_EQ(data.id, 3);
  EXPECT_EQ(data.value, "c");
}

void checkKeys(BaseKey &key) {
  int i = 0;
  for (auto item : list)
    EXPECT_EQ(key.keys[i++], item);
}
