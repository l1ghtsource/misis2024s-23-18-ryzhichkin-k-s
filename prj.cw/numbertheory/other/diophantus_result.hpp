#include <iostream>

struct DiophantusResult {
  DiophantusResult() = default;
  DiophantusResult(int64_t x, int64_t y, int64_t k_1, int64_t k_2) : x(x), y(y), k_1(k_1), k_2(k_2), s("good") {}
  ~DiophantusResult() = default;

  int64_t x = 0;
  int64_t y = 0;
  int64_t k_1 = 0;
  int64_t k_2 = 0;
  std::string s = "none";

  friend std::ostream& operator<<(std::ostream& os, const DiophantusResult& result) {
    if (result.s == "good") {
      os << "(x, y) = " << "(" << result.x << " + " << result.k_1 << "t, " << result.y << " - " << result.k_2 << "t)";
    }
    else {
      os << "There is no integer solutions :(";
    }
    return os;
  }
};