#include "..\numbertheory.hpp"

bool NumberTheory::CheckSumOfSquares(int64_t p) {
  if (IsPrime(p)) {
    // следствие из теоремы Вильсона
    if (p % 4 == 1) {
      return true;
    }
    return false;
  }
  else {
    throw std::invalid_argument("This func is only for prime numbers");
  }
}