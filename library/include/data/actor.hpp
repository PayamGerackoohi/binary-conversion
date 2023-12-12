#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <functional>

template <typename T> struct Actor {
  virtual void action(T &&) = 0;
  operator std::function<void(T &&)>();
};

template <> struct Actor<void> {
  virtual void action() = 0;
  operator std::function<void()>();
};

#include "actor.tpp"

#endif
