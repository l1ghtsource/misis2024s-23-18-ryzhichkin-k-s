#include "..\numbertheory.hpp"

// Euler function (the number of numbers x such that (n, x) = 1, x < n)
int64_t NumberTheory::Phi(int64_t n) {
  int64_t result = n;

  for (int64_t i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      result -= result / i;
    }

  if (n > 1)
    result -= result / n;

  return result;
}
