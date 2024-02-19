#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>
#include <functional>
#include <numeric>

#include "other/extended_euclidean_result.hpp"
#include "other/diophantus_result.hpp"
#include "other/chinese_remainder_theorem_result.hpp"

class NumberTheory {
public:
  // greatest common divisor of two numbers
  int64_t Gcd(int64_t a, int64_t b);

  // least common multiple of two numbers
  int64_t Lcm(int64_t a, int64_t b);

  // greatest common divisor of n numbers
  int64_t Gcd(const std::vector<int64_t>& numbers);

  // least common multiple of n numbers
  int64_t Lcm(const std::vector<int64_t>& numbers);

  // extended Euclid's algorithm (finding x, y such that ax + by = (a, b))
  ExtendedEuclideanResult ExtEuclide(int64_t a, int64_t b);

  // solution of the linear Diophantine equation ax + by = c
  DiophantusResult Diophantus(int64_t a, int64_t b, int64_t c);

  // number of divisors of the number (methods: enum - search of divisors up to the root, fact - through factorization by the formula of the number of divisors)
  int64_t DivisorsCount(int64_t n, std::string method = "enum");

  // sum of divisors of a number (methods: enum - search of divisors up to the root, fact - through factorization by the sum of divisors formula)
  int64_t DivisorsSum(int64_t n, std::string method = "enum");

  // finding the degree of occurrence of a prime number p in n!
  int64_t PrimePowerInFactorial(int64_t n, int64_t p);

  // Eratosthenes sieve (obtaining all prime numbers less than n)
  std::vector<int64_t> SieveOfEratosthenes(int64_t n);

  // modulo inverse element (such that ax = 1 (mod m)), if 0 was returned, then there are no solutions
  int64_t ModInverse(int64_t a, int64_t m);

  // solution of linear comparison ax = b (mod m) by a given modulus 
  std::vector<int64_t> SolveLinearCongruence(int64_t a, int64_t b, int64_t m);

  // solving systems of comparisons of the form x = r_i (mod m_i), all modules of m_i are mutually simple (!!!)
  ChineseRemainderTheoremResult ChineseRemainderTheorem(const std::vector<int64_t>& r, const std::vector<int64_t>& m);

  // Euler function (the number of numbers x such that (n, x) = 1, x < n)
  int64_t Phi(int64_t n);

  // check whether a prime number is representable as the sum of two squares
  bool CheckSumOfSquares(int64_t p);

  // raising a number to a power modulo
  int64_t ModPow(int64_t base, int64_t exp, int64_t m);

  // multiply 2x2 matrices modulo
  std::vector<std::vector<int64_t>> Multiply2x2MatricesMod(std::vector<std::vector<int64_t>>& A, std::vector<std::vector<int64_t>>& B, int64_t m);

  // raising a 2x2 matrix to a power modulo
  std::vector<std::vector<int64_t>> MatrixModPow(std::vector<std::vector<int64_t>>& mat, int64_t exp, int64_t m);

  // calculating Fibonacci numbers modulo
  int64_t ModFib(int64_t n, int64_t m);

  // calculation of the Pisano period (length of the Fibonacci sequence period modulo m)
  int64_t Pisano(int64_t m);

  // check whether g is a prime root modulo m
  bool IsPrimitiveRoot(int64_t g, int64_t m);

  // finding primal roots modulo m
  int64_t FindPrimitiveRoot(int64_t m);

  // Pollard's rho factorization algorithm
  std::vector<int64_t> RhoPollard(int64_t n);

  // checking for freedom from squares
  bool IsSquareFree(int64_t n);
  
  // Möbius function: mu(n) = 0 if n is free from squares, otherwise mu(n) = (-1)^k, where k is the number of prime divisors of n
  int64_t Mobius(int64_t n);

  // check whether a is a quadratic deduction over a prime modulo p
  bool IsQuadraticResidue(int64_t a, int64_t p);

  // Lejandre symbol: (a/p) = 0 if a is divisible by p, (a/p) = 1 if a is a quadratic deduction modulo p and a is not divisible by p, (a/p) = -1 if a is a quadratic non-deduction modulo p
  int64_t LegendreSymbol(int64_t a, int64_t p);

  // Jacobi symbol: (a/P) = (a/p_1)(a/p_2)...(a/p_n), where (a/p_i) are Lejandre symbols
  int64_t JacobiSymbol(int64_t a, int64_t p);

  // simplicity test: accepts a number n and a simplicity test method (list of methods: [sqrt, fermat, frobenius, millerrabin, bpsw]).
  bool IsPrime(int64_t n, std::string method="sqrt");

  // outputs all information about the number n (ADD WHAT IT IS)
  void AllAbout(int64_t n);
};