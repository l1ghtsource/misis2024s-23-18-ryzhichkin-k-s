#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>

#include "other/extended_euclidean_result.hpp"
#include "other/diophantus_result.hpp"

class NumberTheory {
public:
  // наибольший общий делитель двух чисел
  static int64_t Gcd(int64_t a, int64_t b);

  // наименьшее общее кратное двух чисел
  static int64_t Lcm(int64_t a, int64_t b);

  // наибольший общий делитель n чисел
  static int64_t Gcd(std::vector<int64_t > numbers);

  // наименьшее общее кратное n чисел
  static int64_t Lcm(std::vector<int64_t > numbers);

  // расширенный алгоритм Евклида (нахождение x, y, таких, что ax + by = (a, b))
  static ExtendedEuclideanResult ExtEuclide(int64_t a, int64_t b);

  // решение линейного диофантова уравнения ax + by = c
  static DiophantusResult Diophantus(int64_t a, int64_t b, int64_t c);

  // решение линейного сравнения ax = b (mod m) по заданному модулю 
  static std::vector<int64_t> SolveLinearCongruence(const int64_t& a, const int64_t& b, const int64_t& m);

  // обратный по модулю элемент (такой, что ax = 1 (mod m))
  static int64_t ModInverse(const int64_t& a, const int64_t& m);

  // решение систем сравнений вида x = a_i (mod m_i)
  static std::vector<int64_t> SolveLinearCongruenceSystem(const std::vector<int64_t>& a, const std::vector<int64_t>& m);

  // количество делителей числа
  static int64_t DivisorsCount(const int64_t& n);

  // сумма делителей числа
  static int64_t DivisorsSum(const int64_t& n);

  // решето Эратосфена (получение всех простых чисел, меньших n)
  static std::vector<int64_t> SieveOfEratosthenes(const int64_t& n);

  // функция Эйлера (количество чисел x таких, что (n, x) = 1, x < n)
  static int64_t Phi(const int64_t& n);

  // возведение числа в степень по модулю
  static int64_t ModPow(const int64_t& a, const int64_t& m);

  // возведение матрицы 2x2 в степень по модулю
  static int64_t MatrixModPow(const std::vector<std::vector<int64_t>>& mat, const int64_t& m);

  // вычисление чисел Фибоначчи по модулю
  static int64_t ModFib(const int64_t& n, const int64_t& m);

  // вычисление периода Пизано (длина периода последовательности Фибоначчи по модулю m)
  static int64_t Pisano(const int64_t& m);

  // нахождение степени вхождения просто числа p в n!
  static int64_t PrimePowerInFactorial(const int64_t& n);

  // проверка: представимо ли простое число в виде суммы двух квадратов
  static bool CheckSumOfSquares(const int64_t& p);

  // проверка: является ли число g первообразным корнем по модулю m
  static bool IsPrimitiveRoot(const int64_t& g, const int64_t& m);

  // нахождение первообразных корней по модулю m
  static int64_t FindPrimitiveRoot(const int64_t& m);

  // ро-алгоритм факторизации Полларда
  static int64_t RhoPollard(const int64_t& n); 

  // проверка на свободу от квадратов
  static bool IsSquareFree(const int64_t& n);
  
  // функция Мёбиуса: mu(n) = 0, если n свободно от квадратов, иначе mu(n) = (-1)^k, где k - количество простых делителей n
  static int64_t Mobius(const int64_t& n);

  // проверка: является ли число a квадратичным вычетом по простому модулю p
  static bool IsQuadraticResidue(const int64_t& a, const int64_t& p);

  // символ Лежандра: (a/p) = 0, если a делится на p, (a/p) = 1, если a - квадратичный вычет по модулю p и a не делится на p, (a/p) = -1, если a - квадратичный невычет по модулю p
  static int64_t LegendreSymbol(const int64_t& a, const int64_t& p);

  // символ Якоби: (a/P) = (a/p_1)(a/p_2)...(a/p_n), где (a/p_i) - символы Лежандра
  static int64_t JacobiSymbol(const int64_t& a, const int64_t& p);

  // тест на простоту: принимает число n и метод проверки на простоту (список методов: [ЗАПОЛНИТЬ])
  static bool IsPrime(const int64_t& n, std::string method="sqrttest");

  // тест на простоту перебором делителей до корня из n
  static bool SqrtTest(const int64_t& n);

  // вероятностный тест Ферма на простоту
  static bool FermatTest(const int64_t& n);

  // вероятностный тест Фробениуса на простоту
  static bool FrobeniusTest(const int64_t& n); 

  // вероятностный тест Миллера-Рабина на простоту
  static bool MillerRabinTtest(const int64_t& n, const int64_t& num_iterations = 50);

  // выводит всю информацию о числе n (ДОБАВИТЬ ЧТО ИМЕННО)
  void AllAbout(int64_t n);
};