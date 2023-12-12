#include "data/actor.hpp"

Actor<void>::operator std::function<void()>() {
  return [&]() { action(); };
}
