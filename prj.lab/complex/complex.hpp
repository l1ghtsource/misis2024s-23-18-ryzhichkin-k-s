#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

struct Complex {
  [[nodiscard]] Complex() = default;
  [[nodiscard]] Complex(const Complex&) = default;
  [[nodiscard]] Complex(const double real) : re(real), im(0.0) {}
  [[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
  ~Complex() = default;

  [[nodiscard]] Complex& operator=(const Complex&) = default;

  [[nodiscard]] Complex operator-() const noexcept { return { -re, -im }; }

  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs);
  Complex& operator/=(const Complex& rhs);
  Complex& operator/=(const double rhs);

  [[nodiscard]] std::ostream& writeTo(std::ostream& ostrm) const noexcept;
  [[nodiscard]] std::istream& readFrom(std::istream& istrm) noexcept;

  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs);

[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}

[[nodiscard]] bool operator==(const Complex& lhs, const Complex& rhs);
[[nodiscard]] bool operator!=(const Complex& lhs, const Complex& rhs);

Complex degree(const Complex& lhs, const int rhs);
std::vector<Complex> root(const Complex& lhs, const int rhs);
double arg(const Complex& z);
double modulus(const Complex& z);

bool is_equal(const double& x, const double& y);
bool is_equal_complex(const Complex& lhs, const Complex& rhs);
bool is_equal_vector(const std::vector<Complex>& lhs, const std::vector<Complex>& rhs);

#endif