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

  // количество делителей числа (методы: enum - перебор делителей до корня, fact - через факторизацию по формуле количества делителей)
  static int64_t DivisorsCount(int64_t n, std::string method = "enum");

  // сумма делителей числа (методы: enum - перебор делителей до корня, fact - через факторизацию по формуле суммы делителей)
  static int64_t DivisorsSum(int64_t n, std::string method = "enum");

  // нахождение степени вхождения просто числа p в n!
  static int64_t PrimePowerInFactorial(int64_t n, int64_t p);

  // решение линейного сравнения ax = b (mod m) по заданному модулю 
  static std::vector<int64_t> SolveLinearCongruence(int64_t a, int64_t b, int64_t m);

  // обратный по модулю элемент (такой, что ax = 1 (mod m))
  static int64_t ModInverse(int64_t a, int64_t m);

  // решение систем сравнений вида x = a_i (mod m_i)
  static std::vector<int64_t> SolveLinearCongruenceSystem(std::vector<int64_t>& a, std::vector<int64_t>& m);

  // решето Эратосфена (получение всех простых чисел, меньших n)
  static std::vector<int64_t> SieveOfEratosthenes(int64_t n);

  // функция Эйлера (количество чисел x таких, что (n, x) = 1, x < n)
  static int64_t Phi(int64_t n);

  // возведение числа в степень по модулю
  static int64_t ModPow(int64_t a, int64_t m);

  // возведение матрицы 2x2 в степень по модулю
  static int64_t MatrixModPow(std::vector<std::vector<int64_t>>& mat, int64_t m);

  // вычисление чисел Фибоначчи по модулю
  static int64_t ModFib(int64_t n, int64_t m);

  // вычисление периода Пизано (длина периода последовательности Фибоначчи по модулю m)
  static int64_t Pisano(int64_t m);

  // проверка: представимо ли простое число в виде суммы двух квадратов
  static bool CheckSumOfSquares(int64_t p);

  // проверка: является ли число g первообразным корнем по модулю m
  static bool IsPrimitiveRoot(int64_t g, int64_t m);

  // нахождение первообразных корней по модулю m
  static int64_t FindPrimitiveRoot(int64_t m);

  // ро-алгоритм факторизации Полларда
  static std::vector<int64_t> RhoPollard(int64_t n);

  // проверка на свободу от квадратов
  static bool IsSquareFree(int64_t n);
  
  // функция Мёбиуса: mu(n) = 0, если n свободно от квадратов, иначе mu(n) = (-1)^k, где k - количество простых делителей n
  static int64_t Mobius(int64_t n);

  // проверка: является ли число a квадратичным вычетом по простому модулю p
  static bool IsQuadraticResidue(int64_t a, int64_t p);

  // символ Лежандра: (a/p) = 0, если a делится на p, (a/p) = 1, если a - квадратичный вычет по модулю p и a не делится на p, (a/p) = -1, если a - квадратичный невычет по модулю p
  static int64_t LegendreSymbol(int64_t a, int64_t p);

  // символ Якоби: (a/P) = (a/p_1)(a/p_2)...(a/p_n), где (a/p_i) - символы Лежандра
  static int64_t JacobiSymbol(int64_t a, int64_t p);

  // тест на простоту: принимает число n и метод проверки на простоту (список методов: [sqrt, fermat, frobenius, millerrabin, bpsw])
  static bool IsPrime(int64_t n, std::string method="sqrt");

  // выводит всю информацию о числе n (ДОБАВИТЬ ЧТО ИМЕННО)
  void AllAbout(int64_t n);
};