#include "actor-test.hpp"
#include <gtest/gtest.h>
#include <utility>

using std::function;
using std::move;
using std::string;

TEST(ActorSuite, voidActor) {
  VoidActor actor;
  actor.action();
  voidAction(actor);
}

TEST(ActorSuite, intActor) {
  IntActor actor;
  actor.action(123);
  intAction(actor);
}

TEST(ActorSuite, dataActor) {
  DataActor actor;
  actor.action(Data(1, "2"));
  Data data(1, "2");
  actor.action(move(data));
  dataAction(actor);
}

void VoidActor::action() {}

void IntActor::action(int &&i) { EXPECT_EQ(i, 123); }

void DataActor::action(Data &&d) {
  EXPECT_EQ(d.id, 1);
  EXPECT_EQ(d.value, "2");
}

void voidAction(function<void()> action) {}

void intAction(function<void(int &&)> action) { action(123); }

void dataAction(function<void(Data &&)> action) { action(Data(1, "2")); }
