#include <iostream>

struct ExtendedEuclideanResult {
  ExtendedEuclideanResult(int64_t gcd, int64_t x, int64_t y) : gcd(gcd), x(x), y(y) {}
  ~ExtendedEuclideanResult() = default;

  int64_t gcd; // НОД(a, b)
  int64_t x;   // коэффициент x
  int64_t y;   // коэффициент y

  friend std::ostream& operator<<(std::ostream& os, const ExtendedEuclideanResult& result) {
    os << "GCD: " << result.gcd << ", x: " << result.x << ", y: " << result.y;
    return os;
  }
};
