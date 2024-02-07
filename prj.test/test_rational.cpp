#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <rational/rational.hpp>
#include <rational/rational.cpp>
#include "doctest.h"

TEST_CASE("rational ctor and simplifier") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  Rational r{ 4, 5 };
  CHECK(4 == r.num());
  CHECK(5 == r.den());

  Rational r_2{ 16, 24 };
  CHECK(2 == r_2.num());
  CHECK(3 == r_2.den());

  Rational r_3{ -1, 2 };
  CHECK(-1 == r_3.num());
  CHECK(2 == r_3.den());

  Rational r_4{ 1, -3 };
  CHECK(-1 == r_4.num());
  CHECK(3 == r_4.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("operators") {
  Rational r_1{ 2, -6 };
  Rational r_2{ 7, 28 };
  Rational r_3{ 0, 128 };

  int64_t a = 1;
  int64_t b = 2;

  Rational sum{ -1, 12 };
  Rational difference{ -7, 12 };
  Rational product{ -1, 12 };
  Rational quotient{ -4, 3 };

  Rational sum_2{ 2, 3 };
  Rational difference_2{ -4, 3 };
  Rational difference_3{ 4, 3 };
  Rational product_2{ -2, 3 };
  Rational quotient_2{ -1, 6 };
  Rational quotient_3{ -6, 1 };

  CHECK(sum == (r_1 + r_2));
  CHECK(difference == (r_1 - r_2));
  CHECK(product == (r_1 * r_2));
  CHECK(quotient == (r_1 / r_2));
  CHECK(sum_2 == (a + r_1));
  CHECK(sum_2 == (r_1 + a));
  CHECK(difference_2 == (r_1 - a));
  CHECK(difference_3 == (a - r_1));
  CHECK(product_2 == (b * r_1));
  CHECK(product_2 == (r_1 * b));
  CHECK(quotient_2 == (r_1 / b));
  CHECK(quotient_3 == (b / r_1));
}