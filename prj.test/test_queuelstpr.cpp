#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <queuelstpr/queuelstpr.hpp>

#include <cstdint>

TEST_CASE("queuelstpr ctor") {
  QueueLstPr queue;
  CHECK_EQ(queue.IsEmpty(), 1);
  QueueLstPr queue_copy(queue);
  QueueLstPr queue_again = queue_copy;
  CHECK_EQ(queue_copy.IsEmpty(), 1);
}

TEST_CASE("push, pop, top, clear") {
  QueueLstPr queue;
  CHECK_THROWS(void(queue.Top()));
  queue.Push(1);
  CHECK_EQ(queue.IsEmpty(), 0);
  queue.Push(2);
  queue.Push(0.5);
  queue.Push(0.6);
  CHECK_EQ(queue.Top(), float(0.5));
  queue.Pop();
  CHECK_EQ(queue.Top(), float(0.6));
}
