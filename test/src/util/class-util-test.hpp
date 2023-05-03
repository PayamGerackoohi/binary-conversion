#ifndef struct_UTIL_TEST_HPP
#define struct_UTIL_TEST_HPP

struct A {
  virtual ~A() = default;
};
struct B : A {};
template <typename T> struct C : B {
  virtual ~C() = default;
};
template <> struct C<void> : A {
  virtual ~C() = default;
};
struct D : C<int> {};
struct E : C<void> {};

#endif
