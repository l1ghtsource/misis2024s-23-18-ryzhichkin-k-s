﻿#include "../prj.cw/numbertheory/numbertheory.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << "[ ";
  for (const auto& element : vec) {
    os << element << " ";
  }
  os << "]";
  return os;
}

int main() {
  std::cout.setf(std::ios_base::boolalpha);
  NumberTheory NT = NumberTheory();

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

  std::cout << NT.SieveOfEratosthenes(100) << std::endl;

  std::cout << NT.ModInverse(7, 26) << std::endl;

  std::cout << NT.SolveLinearCongruence(6, 26, 22) << std::endl;

  std::cout << NT.ChineseRemainderTheorem(std::vector<int64_t>{ 2, 3, 2 }, std::vector<int64_t>{ 3, 5, 7 }) << std::endl;

  std::cout << NT.CheckSumOfSquares(17) << std::endl;

  std::cout << NT.Phi(10) << std::endl;

  std::cout << NT.ModPow(279, 644, 7826) << std::endl;

  std::cout << NT.ModFib(10, 54) << std::endl;

  std::cout << NT.Pisano(10) << std::endl;

  std::cout << NT.IsPrimitiveRoot(2, 13) << std::endl;
  std::cout << NT.IsPrimitiveRoot(3, 7) << std::endl;
  std::cout << NT.IsPrimitiveRoot(7, 15) << std::endl;

  std::cout << NT.FindPrimitiveRoots(13) << std::endl;
  std::cout << NT.FindPrimitiveRoots(15) << std::endl;

  std::cout << NT.IsSquareFree(124579) << std::endl;
  std::cout << NT.IsSquareFree(4123) << std::endl;

  std::cout << NT.Mobius(12) << std::endl;
  std::cout << NT.Mobius(1234) << std::endl;
  std::cout << NT.Mobius(12345) << std::endl;

  std::cout << NT.IsQuadraticResidue(25, 31) << std::endl;
  std::cout << NT.IsQuadraticResidue(7, 31) << std::endl;
  std::cout << NT.IsQuadraticResidue(11, 31) << std::endl;

  std::cout << NT.LegendreSymbol(134, 31) << std::endl;
  std::cout << NT.LegendreSymbol(6, 31) << std::endl;
  std::cout << NT.LegendreSymbol(78678, 31) << std::endl;

  std::cout << NT.JacobiSymbol(34, 5345) << std::endl;
  std::cout << NT.JacobiSymbol(345, 565) << std::endl;
  std::cout << NT.JacobiSymbol(1234, 4567) << std::endl;

  return 0;
}