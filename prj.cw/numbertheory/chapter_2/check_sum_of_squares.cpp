#include "..\numbertheory.hpp"

// check whether a prime number is representable as the sum of two squares
bool NumberTheory::CheckSumOfSquares(int64_t p) {
  if (IsPrime(p)) {
    // corollary of Wilson's theorem
    if (p % 4 == 1) {
      return true;
    }
    return false;
  }
  else {
    throw std::invalid_argument("This function is only for prime numbers");
  }
}