#ifndef ACTOR_TEST_HPP
#define ACTOR_TEST_HPP

#include "data/actor.hpp"
#include "test-util/data.hpp"
#include <string>

struct VoidActor : Actor<void> {
  void action() override;
};

struct DataActor : Actor<Data> {
  void action(Data &&) override;
};

struct IntActor : Actor<int> {
  void action(int &&) override;
};

void voidAction(std::function<void()>);
void intAction(std::function<void(int &&)>);
void dataAction(std::function<void(Data &&)>);

#endif
