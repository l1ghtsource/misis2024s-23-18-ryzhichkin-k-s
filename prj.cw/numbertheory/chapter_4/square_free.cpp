#include "..\numbertheory.hpp"

// checking for freedom from squares
bool NumberTheory::IsSquareFree(int64_t n) {
  if (n <= 1) {
    return true;
  }
  for (int64_t i = 2; i * i <= n; ++i) {
    if (n % (i * i) == 0) {
      return false;
    }
  }
  return true;
}

// Möbius function: mu(n) = 0 if n is free from squares, otherwise mu(n) = (-1)^k, where k is the number of prime divisors of n
int64_t NumberTheory::Mobius(int64_t n) {
  return 0;
}