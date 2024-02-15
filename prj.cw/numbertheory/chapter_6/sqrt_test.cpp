#include "../numbertheory.hpp"

// тест на простоту перебором делителей до корня из n
bool SqrtTest(int64_t n) {
  if (n == 1) {
    return false;
  }
  for (int64_t i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}