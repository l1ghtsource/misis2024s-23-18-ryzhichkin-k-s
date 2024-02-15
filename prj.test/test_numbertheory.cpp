﻿#include "../prj.cw/numbertheory/numbertheory.hpp"

int main() {
  NumberTheory NT = NumberTheory();

  std::cout << NT.Gcd(39, 52) << std::endl;
  std::cout << NT.Gcd(39, 52) << std::endl;
  std::cout << NT.Lcm(39, 52) << std::endl;

  std::cout << NT.Gcd(std::vector<int64_t>{39, 52, 65}) << std::endl;
  std::cout << NT.Lcm(std::vector<int64_t>{39, 52, 65}) << std::endl;

  std::cout << NT.ExtEuclide(39, 65) << std::endl;

  std::cout << NT.Diophantus(-13, -4, 5) << std::endl;
  std::cout << NT.Diophantus(5, 15, 3) << std::endl;

  std::cout << NT.DivisorsCount(12, "enum") << std::endl;
  std::cout << NT.DivisorsSum(25, "enum") << std::endl;

  std::cout << NT.PrimePowerInFactorial(6, 2) << std::endl;

  return 0;
}