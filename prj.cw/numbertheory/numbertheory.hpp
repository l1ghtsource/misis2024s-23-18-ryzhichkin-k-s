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
  int64_t Gcd(int64_t a, int64_t b);

  // наименьшее общее кратное двух чисел
  int64_t Lcm(int64_t a, int64_t b);

  // наибольший общий делитель n чисел
  int64_t Gcd(std::vector<int64_t > numbers);

  // наименьшее общее кратное n чисел
  int64_t Lcm(std::vector<int64_t > numbers);

  // расширенный алгоритм Евклида (нахождение x, y, таких, что ax + by = (a, b))
  ExtendedEuclideanResult ExtEuclide(int64_t a, int64_t b);

  // решение линейного диофантова уравнения ax + by = c
  DiophantusResult Diophantus(int64_t a, int64_t b, int64_t c);

  // количество делителей числа (методы: enum - перебор делителей до корня, fact - через факторизацию по формуле количества делителей)
  int64_t DivisorsCount(int64_t n, std::string method = "enum");

  // сумма делителей числа (методы: enum - перебор делителей до корня, fact - через факторизацию по формуле суммы делителей)
  int64_t DivisorsSum(int64_t n, std::string method = "enum");

  // нахождение степени вхождения просто числа p в n!
  int64_t PrimePowerInFactorial(int64_t n, int64_t p);

  // решето Эратосфена (получение всех простых чисел, меньших n)
  std::vector<int64_t> SieveOfEratosthenes(int64_t n);

  // обратный по модулю элемент (такой, что ax = 1 (mod m)), если был возвращён 0, значит решений нет
  int64_t ModInverse(int64_t a, int64_t m);

  // решение линейного сравнения ax = b (mod m) по заданному модулю 
  std::vector<int64_t> SolveLinearCongruence(int64_t a, int64_t b, int64_t m);

  // решение систем сравнений вида x = a_i (mod m_i)
  std::vector<int64_t> SolveLinearCongruenceSystem(std::vector<int64_t>& a, std::vector<int64_t>& m);

  // проверка: представимо ли простое число в виде суммы двух квадратов
  bool CheckSumOfSquares(int64_t p);

  // функция Эйлера (количество чисел x таких, что (n, x) = 1, x < n)
  int64_t Phi(int64_t n);

  // возведение числа в степень по модулю
  int64_t ModPow(int64_t a, int64_t m);

  // возведение матрицы 2x2 в степень по модулю
  int64_t MatrixModPow(std::vector<std::vector<int64_t>>& mat, int64_t m);

  // вычисление чисел Фибоначчи по модулю
  int64_t ModFib(int64_t n, int64_t m);

  // вычисление периода Пизано (длина периода последовательности Фибоначчи по модулю m)
  int64_t Pisano(int64_t m);

  // проверка: является ли число g первообразным корнем по модулю m
  bool IsPrimitiveRoot(int64_t g, int64_t m);

  // нахождение первообразных корней по модулю m
  int64_t FindPrimitiveRoot(int64_t m);

  // ро-алгоритм факторизации Полларда
  std::vector<int64_t> RhoPollard(int64_t n);

  // проверка на свободу от квадратов
  bool IsSquareFree(int64_t n);
  
  // функция Мёбиуса: mu(n) = 0, если n свободно от квадратов, иначе mu(n) = (-1)^k, где k - количество простых делителей n
  int64_t Mobius(int64_t n);

  // проверка: является ли число a квадратичным вычетом по простому модулю p
  bool IsQuadraticResidue(int64_t a, int64_t p);

  // символ Лежандра: (a/p) = 0, если a делится на p, (a/p) = 1, если a - квадратичный вычет по модулю p и a не делится на p, (a/p) = -1, если a - квадратичный невычет по модулю p
  int64_t LegendreSymbol(int64_t a, int64_t p);

  // символ Якоби: (a/P) = (a/p_1)(a/p_2)...(a/p_n), где (a/p_i) - символы Лежандра
  int64_t JacobiSymbol(int64_t a, int64_t p);

  // тест на простоту: принимает число n и метод проверки на простоту (список методов: [sqrt, fermat, frobenius, millerrabin, bpsw])
  bool IsPrime(int64_t n, std::string method="sqrt");

  // выводит всю информацию о числе n (ДОБАВИТЬ ЧТО ИМЕННО)
  void AllAbout(int64_t n);
};