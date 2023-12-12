template <typename T> Key<T>::Key(KeyList &&list, std::function<void(T &&)> &&action) : BaseKey(std::move(list)) { this->action = action; }
