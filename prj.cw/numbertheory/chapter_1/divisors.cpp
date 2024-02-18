#include "../numbertheory.hpp"

// number of divisors of the number (methods: enum - search of divisors up to the root, fact - through factorization by the formula of the number of divisors)
int64_t NumberTheory::DivisorsCount(int64_t n, std::string method) {
  n = std::abs(n);

  if (method == "enum") {
    int64_t count = 0;
    for (int64_t i = 1; i <= static_cast<int64_t>(std::sqrt(n)); ++i) {
      if (n % i == 0) {
        count += (i == n / i) ? 1 : 2;
      }
    }
    return count;
  }

  else if (method == "fact") {
    return 1;
  }

  else {
    throw std::invalid_argument("Select a method from the list: [enum, fact]");
  }
}

// sum of divisors of a number (methods: enum - search of divisors up to the root, fact - through factorization by the sum of divisors formula)
int64_t NumberTheory::DivisorsSum(int64_t n, std::string method) {
  n = std::abs(n);

  if (method == "enum") {
    int64_t sum = 0;
    for (int64_t i = 1; i <= static_cast<int64_t>(std::sqrt(n)); ++i) {
      if (n % i == 0) {
        sum += i;
        if (i != n / i) {
          sum += n / i;
        }
      }
    }
    return sum;
  }

  else if (method == "fact") {
    return 1;
  }

  else {
    throw std::invalid_argument("Select a method from the list: [enum, fact]");
  }
}
