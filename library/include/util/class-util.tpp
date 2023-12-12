template <typename P, typename I> inline bool instanceof (I * i) { return dynamic_cast<P *>(i) != nullptr; }
