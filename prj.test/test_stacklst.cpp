#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stacklst/stacklst.hpp>
#include <complex/complex.hpp>

#include <cstdint>

TEST_CASE("stacklst ctor") {
  StackLst stack;
  CHECK_EQ(stack.IsEmpty(), 1);
  StackLst stack_copy(stack);
  CHECK_EQ(stack_copy.IsEmpty(), 1);
}
TEST_CASE("push, pop, top, clear") {
  StackLst stack;
  CHECK_THROWS(void(stack.Top()));
  stack.Push(Complex(1, 2));
  CHECK_EQ(stack.IsEmpty(), 0);
  CHECK_EQ(stack.Top(), Complex(1, 2));
  stack.Pop();
  CHECK_EQ(stack.IsEmpty(), 1);
  stack.Push(Complex(1));
  stack.Clear();
  CHECK_EQ(stack.IsEmpty(), 1);
}
