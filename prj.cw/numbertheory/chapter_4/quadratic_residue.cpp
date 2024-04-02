#include "..\numbertheory.hpp"

// check whether a is a quadratic deduction over a prime modulo p
bool NumberTheory::IsQuadraticResidue(int64_t a, int64_t p) {
  if (!IsPrime(p) or p <= 2) {
    throw std::invalid_argument("Modulo should be prime and > 2");
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
  if (!IsPrime(p) or p <= 2) {
    throw std::invalid_argument("Modulo should be prime and > 2");
  }

  else if (a % p == 0) {
    return 0;
  }

  else if (IsQuadraticResidue(a, p)) {
    return 1;
  }

  return -1;
}

// Jacobi symbol: (a/P) = (a/p_1)(a/p_2)...(a/p_n), where (a/p_i) are Lejandre symbols
int64_t NumberTheory::JacobiSymbol(int64_t a, int64_t n) {
  if (n <= 0 || n % 2 == 0) {
    throw std::invalid_argument("Modulus must be a positive odd number");
  }

  int64_t symbol = 1;

  while (a != 0) {
    while (a % 2 == 0) {
      a /= 2;
      int64_t r = n % 8;
      if (r == 3 || r == 5)
        symbol = -symbol;
    }

    std::swap(a, n);

    if (a % 4 == 3 && n % 4 == 3)
      symbol = -symbol;

    a %= n;
  }

  if (n == 1)
    return symbol;
  else
    return symbol * LegendreSymbol(a, n);
}