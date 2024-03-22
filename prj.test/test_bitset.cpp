#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <bitset/bitset.hpp>

#include <cstdint>

TEST_CASE("all in one") {
  BitSet bs = BitSet();
  CHECK_THROWS(bs.Get(1));
  CHECK_THROWS(bs.Set(65, 0));
  CHECK_EQ(bs.Size(), 0);
  bs.Resize(15);
  CHECK_EQ(bs.Size(), 15);
  bs.Set(14, 1);
  CHECK_EQ(bs.Get(14), 1);
  bs.Set(3, 0);
  CHECK_EQ(bs.Get(3), 0);
}

