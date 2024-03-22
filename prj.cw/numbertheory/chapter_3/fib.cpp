#include "..\numbertheory.hpp"

// calculating Fibonacci numbers modulo
int64_t NumberTheory::ModFib(int64_t n, int64_t m) {
  std::vector<std::vector<int64_t>> F_1 = { {0, 1}, {1, 1} };
  std::vector<std::vector<int64_t>> F = MatrixModPow(F_1, n, m);

  return F[0][1];
}

// calculation of the Pisano period (length of the Fibonacci sequence period modulo m)
int64_t NumberTheory::Pisano(int64_t m) {
  std::vector<int64_t> v{ 1, 1 };
  while (true) {
    auto t = (v[v.size() - 1] + v[v.size() - 2]) % m;
    v.push_back(t);
    if (t == 0 && v.size() % 2 == 0 &&
      std::equal(v.begin(), v.begin() + v.size() / 2,
        v.begin() + v.size() / 2, v.end())) {
      return v.size() / 2;
    }
  }
  return v.size() / 2;
}