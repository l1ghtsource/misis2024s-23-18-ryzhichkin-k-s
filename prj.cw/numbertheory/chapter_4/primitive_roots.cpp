#include "..\numbertheory.hpp"

// check whether g is a prime root modulo m
bool NumberTheory::IsPrimitiveRoot(int64_t g, int64_t m) {
  if (m <= 1) {
    throw std::invalid_argument("Modulo should be > 1");
  }

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
std::vector<int64_t> NumberTheory::FindPrimitiveRoots(int64_t m) {
  if (m <= 1) {
    throw std::invalid_argument("Modulo should be > 1");
  }

  std::vector<int64_t> roots;

  for (int64_t g = 2; g < m; ++g) {
    if (IsPrimitiveRoot(g, m)) {
      roots.push_back(g);
    }
  }

  return roots;
}