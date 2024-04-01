#include "sqrt_test.cpp"
#include "fermat.cpp"
#include "frobenius.cpp"
#include "millerrabin.cpp"
#include "bpsw.cpp"

bool NumberTheory::IsPrime(int64_t n, std::string method) {
  if (method == "sqrt") {
    return SqrtTest(n);
  }

  else if (method == "fermat") {
    return FermatTest(n);
  }

  else if (method == "frobenius") {
    return FrobeniusTest(n);
  }

  else if (method == "millerrabin") {
    return MillerRabinTtest(n);
  }

  else if (method == "bpsw") {
    return BPSW(n);
  }

  else {
    throw std::invalid_argument("List of methods: [sqrt, fermat, frobenius, millerrabin, bpsw]");
  }
}