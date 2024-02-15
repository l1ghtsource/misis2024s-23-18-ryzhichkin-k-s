#include <iostream>

struct ExtendedEuclideanResult {
  ExtendedEuclideanResult() = default;
  ~ExtendedEuclideanResult() = default;

  int64_t gcd; // ���(a, b)
  int64_t x;   // ����������� x
  int64_t y;   // ����������� y

  friend std::ostream& operator<<(std::ostream& os, const ExtendedEuclideanResult& result) {
    os << "GCD: " << result.gcd << ", x: " << result.x << ", y: " << result.y;
    return os;
  }

};