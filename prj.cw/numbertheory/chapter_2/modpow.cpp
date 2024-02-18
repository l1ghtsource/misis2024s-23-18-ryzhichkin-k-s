#include "..\numbertheory.hpp"

// raising a number to a power modulo
int64_t NumberTheory::ModPow(int64_t base, int64_t exp, int64_t m) {
  int64_t result = 1;
  base %= m;

  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % m;
    }
    base = (base * base) % m;
    exp >>= 1;
  }
  return result;
}