template <typename T> Actor<T>::operator std::function<void(T &&)>() {
  return [&](T &&t) { action(std::move(t)); };
}
