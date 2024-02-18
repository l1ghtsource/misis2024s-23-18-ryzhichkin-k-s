#include <iostream>

struct ChineseRemainderTheoremResult {
  ChineseRemainderTheoremResult(int64_t res, int64_t mod) : res(res), mod(mod) {}
  ~ChineseRemainderTheoremResult() = default;

  int64_t res = 0;
  int64_t mod = 0;

  friend std::ostream& operator<<(std::ostream& os, const ChineseRemainderTheoremResult& result) {
    os << "Solution: x = " << result.res << " (mod " << result.mod << ")";
    return os;
  }
};