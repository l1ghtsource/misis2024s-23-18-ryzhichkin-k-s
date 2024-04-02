#include "..\numbertheory.hpp"

// check whether a is a quadratic deduction over a prime modulo p
bool NumberTheory::IsQuadraticResidue(int64_t a, int64_t p) {
  if (p < 1) {
    throw std::invalid_argument("Modulo should be positive");
  }
  else if (!IsPrime(p)) {
    throw std::invalid_argument("Modulo should be prime");
  }
  else if (a == 0) {
    return false;
  }

  a = a % p;
  if (a < 0) {
    a += p;
  }

  return ModPow(a, (p - 1) / 2, p) == 1;
}

// Lejandre symbol: (a/p) = 0 if a is divisible by p, (a/p) = 1 if a is a quadratic deduction modulo p and a is not divisible by p, (a/p) = -1 if a is a quadratic non-deduction modulo p
int64_t NumberTheory::LegendreSymbol(int64_t a, int64_t p) {
  return 0;
}

// Jacobi symbol: (a/P) = (a/p_1)(a/p_2)...(a/p_n), where (a/p_i) are Lejandre symbols
int64_t NumberTheory::JacobiSymbol(int64_t a, int64_t p) {
  return 0;
}