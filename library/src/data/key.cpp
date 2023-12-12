#include "data/key.hpp"
#include "util/color.hpp"
#include <iostream>

BaseKey::BaseKey(KeyList &&list) : keys{list} {
  if (keys.empty()) {
    std::cerr << payam::red << "The key list cannot be empty." << std::endl;
    exit(1);
  }
}

Key<void>::Key(KeyList &&list, std::function<void()> &&action) : BaseKey(std::move(list)) {
  this->action = action;
}
