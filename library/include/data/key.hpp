#ifndef KEY_HPP
#define KEY_HPP

#include <functional>
#include <string>
#include <vector>

using KeyList = std::initializer_list<std::string>;

struct BaseKey {
  std::vector<std::string> keys;

  virtual ~BaseKey() = default;
  BaseKey(KeyList &&list);
};

template <typename T> struct Key : public BaseKey {
  std::function<void(T &&)> action;

  Key(KeyList &&, std::function<void(T &&)> &&);
};

template <> struct Key<void> : public BaseKey {
  std::function<void()> action;

  Key(KeyList &&, std::function<void()> &&);
};

#include "key.tpp"

#endif
