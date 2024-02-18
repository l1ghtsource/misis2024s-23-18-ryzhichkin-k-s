#include <iostream>

struct ExtendedEuclideanResult {
  ExtendedEuclideanResult(int64_t gcd, int64_t x, int64_t y) : gcd(gcd), x(x), y(y) {}
  ~ExtendedEuclideanResult() = default;

  int64_t gcd; // GCD(a, b)
  int64_t x;   // coefficient x
  int64_t y;   // coefficient y

  friend std::ostream& operator<<(std::ostream& os, const ExtendedEuclideanResult& result) {
    os << "GCD: " << result.gcd << ", x: " << result.x << ", y: " << result.y;
    return os;
  }
};