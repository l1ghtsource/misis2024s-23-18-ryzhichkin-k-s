#include <iostream>

struct ExtendedEuclideanResult {
  ExtendedEuclideanResult() = default;
  ~ExtendedEuclideanResult() = default;

  int64_t gcd; // НОД(a, b)
  int64_t x;   // коэффициент x
  int64_t y;   // коэффициент y

  friend std::ostream& operator<<(std::ostream& os, const ExtendedEuclideanResult& result) {
    os << "GCD: " << result.gcd << ", x: " << result.x << ", y: " << result.y;
    return os;
  }

};