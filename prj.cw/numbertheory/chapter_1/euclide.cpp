#include "../numbertheory.hpp"

// содержит алгоритмы нахождения НОДа и НОКа 2-х или нескольких чисел, расширенный алгоритм Евклида, а также алгоритм решения линейного диофантова уравнения

int64_t NumberTheory::Gcd(int64_t a, int64_t b) {
  while (b != 0) {
    int64_t temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int64_t NumberTheory::Lcm(int64_t a, int64_t b) {
  return a * b / Gcd(a, b);
}

int64_t NumberTheory::Gcd(std::vector<int64_t> numbers) {
  int64_t res = numbers[0];
  for (int i = 1; i < numbers.size(); ++i) {
    res = Gcd(res, numbers[i]);
  }
  return res;
}

int64_t NumberTheory::Lcm(std::vector<int64_t> numbers) {
  int64_t res = numbers[0];
  for (int i = 1; i < numbers.size(); ++i) {
    res = Lcm(res, numbers[i]);
  }
  return res;
}

ExtendedEuclideanResult NumberTheory::ExtEuclide(int64_t a, int64_t b) {
  int64_t x = 0, y = 1, lastX = 1, lastY = 0, temp;
  while (b != 0) {
    int64_t quotient = a / b;
    int64_t remainder = a % b;

    a = b;
    b = remainder;

    temp = x;
    x = lastX - quotient * x;
    lastX = temp;

    temp = y;
    y = lastY - quotient * y;
    lastY = temp;
  }

  ExtendedEuclideanResult result;
  result.gcd = a;
  result.x = lastX;
  result.y = lastY;
  return result;
}

std::tuple<int64_t, int64_t> NumberTheory::Diophantus(int64_t a, int64_t b, int64_t c) {
  return std::tuple<int64_t, int64_t>();
}