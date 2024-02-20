#include "..\numbertheory.hpp"

// raising a number to a power modulo
int64_t NumberTheory::ModPow(int64_t base, int64_t exp, int64_t m) {
  if (exp == 0)
    return 1;
  int64_t temp = ModPow(base, exp / 2, m) % m;
  if (exp % 2 == 0)
    return (temp * temp) % m;
  return (base * temp * temp) % m;
}

// multiply 2x2 matrices modulo
std::vector<std::vector<int64_t>> NumberTheory::Multiply2x2MatricesMod(std::vector<std::vector<int64_t>>& A, std::vector<std::vector<int64_t>>& B, int64_t m) {
  std::vector<std::vector<int64_t>> C = { {0, 0}, {0, 0} };

  C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % m;
  C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % m;
  C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % m;
  C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % m;

  return C;
}

// raising a 2x2 matrix to a power modulo
std::vector<std::vector<int64_t>> NumberTheory::MatrixModPow(std::vector<std::vector<int64_t>>& mat, int64_t exp, int64_t m) {
  if (exp == 0) {
    return std::vector<std::vector<int64_t>>{ {1, 0}, {0, 1} };
  }
  if (exp % 2 == 0) {
    std::vector<std::vector<int64_t>> A = MatrixModPow(mat, exp / 2, m);
    return Multiply2x2MatricesMod(A, A, m);
  }
  else {
    std::vector<std::vector<int64_t>> A = MatrixModPow(mat, (exp - 1) / 2, m);
    std::vector<std::vector<int64_t>> B = Multiply2x2MatricesMod(A, A, m);

    return Multiply2x2MatricesMod(B, mat, m);
  }
}