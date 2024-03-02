#include <queuearr/queuearr.hpp>
#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstdint>

TEST_CASE("all in one cuz 'm lazy") {
  QueueArr q;
  CHECK_EQ(q.IsEmpty(), 1);
  QueueArr q_copy(q);
  CHECK_EQ(q_copy.IsEmpty(), 1);
  CHECK_THROWS(void(q.Top()));
  q.Push(Complex(1, 2));
  CHECK_EQ(q.IsEmpty(), 0);
  CHECK_EQ(q.Top(), Complex(1, 2));
  q.Pop();
  CHECK_EQ(q.IsEmpty(), 1);
  q.Push(Complex(1));
  q.Clear();
  CHECK_EQ(q.IsEmpty(), 1);
}