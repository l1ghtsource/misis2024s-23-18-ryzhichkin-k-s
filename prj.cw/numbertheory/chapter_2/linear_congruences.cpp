#include "..\numbertheory.hpp"

int64_t NumberTheory::ModInverse(int64_t a, int64_t m) {
  if (a == 0 || Gcd(m, a) != 1) {
    return 0;
  }

  ExtendedEuclideanResult euclide = ExtEuclide(a, m);
  int64_t result = ((euclide.x % m) + m) % m;

  return result;
}

std::vector<int64_t> NumberTheory::SolveLinearCongruence(int64_t a, int64_t b, int64_t m) {
  int64_t d = Gcd(a, m);

  if (b % d != 0) {
    return std::vector<int64_t>{ 0 }; // нет решений
  }

  a /= d;
  b /= d;
  m /= d;

  int64_t x_0 = ModInverse(a, m) * b % m;

  std::vector<int64_t> result{ x_0 };

  for (int64_t k = 1; k < d; ++k) {
    result.push_back(x_0 + k * m);
  }

  return result;
}