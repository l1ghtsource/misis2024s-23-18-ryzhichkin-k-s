#include "sqrt_test.cpp"
#include "fermat.cpp"
#include "frobenius.cpp"
#include "millerrabin.cpp"
#include "bpsw.cpp"

bool NumberTheory::IsPrime(int64_t n, std::string method) {
  if (method == "sqrt") {
    return SqrtTest(n);
  }
  return false;
  // добавить другие методы
}