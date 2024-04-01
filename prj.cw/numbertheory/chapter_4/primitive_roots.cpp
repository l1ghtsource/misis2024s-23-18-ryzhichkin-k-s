#include "..\numbertheory.hpp"

// check whether g is a prime root modulo m
bool NumberTheory::IsPrimitiveRoot(int64_t g, int64_t m) {
  int64_t p = Phi(m);

  if (ModPow(g, p, m) != 1) {
    return false;
  }

  for (int64_t q = 2; q * q <= p; ++q) {
    if (p % q == 0 && ModPow(g, p / q, m) == 1) {
      return false;
    }
  }

  return true;
}

// finding primal roots modulo m
int64_t NumberTheory::FindPrimitiveRoot(int64_t m) {
  return 0;
}