#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <queuelst/queuelst.hpp>
#include <complex/complex.hpp>

#include <cstdint>

TEST_CASE("queuelst ctor") {
  QueueLst queue;
  CHECK_EQ(queue.IsEmpty(), 1);
  QueueLst queue_copy(queue);
  QueueLst queue_again = queue_copy;
  CHECK_EQ(queue_copy.IsEmpty(), 1);
}

TEST_CASE("push, pop, top, clear") {
  QueueLst queue;
  CHECK_THROWS(void(queue.Top()));
  queue.Push(Complex(1, 2));
  CHECK_EQ(queue.IsEmpty(), 0);
  CHECK_EQ(queue.Top(), Complex(1, 2));
  queue.Pop();
  CHECK_EQ(queue.IsEmpty(), 1);
  queue.Push(Complex(1));
  CHECK_EQ(queue.Top(), Complex(1));
  QueueLst queue_copy(queue);
  CHECK_EQ(queue_copy.Top(), Complex(1));
  QueueLst queue_again = queue_copy;
  CHECK_EQ(queue_again.Top(), Complex(1));
  queue.Clear();
  CHECK_EQ(queue.IsEmpty(), 1);
}
