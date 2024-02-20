#include "..\numbertheory.hpp"

// calculating Fibonacci numbers modulo
int64_t NumberTheory::ModFib(int64_t n, int64_t m) {
  std::vector<std::vector<int64_t>> F_1 = { {0, 1}, {1, 1} };
  std::vector<std::vector<int64_t>> F = MatrixModPow(F_1, n, m);

  return F[0][1];
}