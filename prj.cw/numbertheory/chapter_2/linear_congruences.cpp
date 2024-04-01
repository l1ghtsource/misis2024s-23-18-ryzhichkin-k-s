#include "..\numbertheory.hpp"

// modulo inverse element (such that ax = 1 (mod m)), if 0 was returned, then there are no solutions
int64_t NumberTheory::ModInverse(int64_t a, int64_t m) {
  if (a == 0 || Gcd(m, a) != 1) {
    return 0;
  }

  ExtendedEuclideanResult euclide = ExtEuclide(a, m);
  int64_t result = ((euclide.x % m) + m) % m;

  return result;
}

// solution of linear comparison ax = b (mod m) by a given modulus 
std::vector<int64_t> NumberTheory::SolveLinearCongruence(int64_t a, int64_t b, int64_t m) {
  int64_t d = Gcd(a, m);

  if (b % d != 0) {
    return std::vector<int64_t>{ 0 }; // no solutions
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

// solving systems of comparisons of the form x = r_i (mod m_i), all modules of m_i are mutually simple (!!!)
ChineseRemainderTheoremResult NumberTheory::ChineseRemainderTheorem(const std::vector<int64_t>& r, const std::vector<int64_t>& m) {
  int64_t n = r.size();
  int64_t t = m.size();

  if (n != t) {
    throw std::invalid_argument("The size of the vector of right sides must be equal to the size of the vector of modules");
  }

  for (int i = 0; i < t; ++i) {
    for (int j = i + 1; j < t; ++j) {
      if (Gcd(m[i], m[j]) != 1) {
        throw std::invalid_argument("Modules must be pairwise coprime");
      }
    }
  }

  int64_t M = std::accumulate(m.begin(), m.end(), 1, std::multiplies<int64_t>());

  std::vector<int64_t> Mod(n);
  std::vector<int64_t> mod(n);
  for (int64_t i = 0; i < n; ++i) {
    Mod[i] = M / m[i];
    mod[i] = ModInverse(Mod[i], m[i]);
  }

  int64_t x = 0;
  for (int i = 0; i < n; ++i) {
    x = (x + r[i] * Mod[i] * mod[i]) % M;
  }

  return ChineseRemainderTheoremResult(x, M);
}
  