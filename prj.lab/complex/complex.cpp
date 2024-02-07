#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

#include <complex/complex.hpp>

bool is_equal(const double& x, const double& y) {
  return std::abs(x - y) <= 2 * std::numeric_limits<double>::epsilon();
}

bool is_equal_complex(const Complex& lhs, const Complex& rhs) {
  return (is_equal(lhs.re, rhs.re)) && (is_equal(lhs.im, rhs.im));
}

bool is_equal_vector(const std::vector<Complex>& lhs, const std::vector<Complex>& rhs) {
  int size_lhs = (int)lhs.size();
  int size_rhs = (int)rhs.size();
  if (size_lhs != size_rhs) {
    return false;
  }
  for (int i = 0; i < size_lhs; ++i) {
    if (!is_equal_complex(lhs[i], rhs[i])) {
      return false;
    }
  }
  return true;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
  return (is_equal(lhs.re, rhs.re) && is_equal(lhs.im, rhs.im));
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
  return !(lhs == rhs);
}

Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) += rhs;
}

Complex operator+(const Complex& lhs, const double rhs) {
  return Complex(lhs) += Complex(rhs);
}

Complex operator+(const double lhs, const Complex& rhs) {
  return Complex(lhs) += Complex(rhs);
}

Complex& Complex::operator-=(const double rhs) {
  re += -rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re += -rhs.re;
  im += -rhs.im;
  return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) -= rhs;
}

Complex operator-(const Complex& lhs, const double rhs) {
  return Complex(lhs) -= Complex(rhs);
}

Complex operator-(const double lhs, const Complex& rhs) {
  return Complex(lhs) -= Complex(rhs);
}

Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double tempRe = re * rhs.re - im * rhs.im;
  double tempIm = re * rhs.im + im * rhs.re;
  re = tempRe;
  im = tempIm;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) *= rhs;
}

Complex operator*(const Complex& lhs, const double rhs) {
  return Complex(lhs) *= Complex(rhs);
}

Complex operator*(const double lhs, const Complex& rhs) {
  return Complex(lhs) *= Complex(rhs);
}

Complex& Complex::operator/=(const double rhs) {
  if (rhs == 0.0) {
    throw std::string("Division by zero");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (denominator == 0.0) {
    throw std::string("Division by zero");
  }
  double newRe = (re * rhs.re + im * rhs.im) / denominator;
  double newIm = (im * rhs.re - re * rhs.im) / denominator;
  re = newRe;
  im = newIm;
  return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs) /= rhs;
}

Complex operator/(const Complex& lhs, const double rhs) {
  return Complex(lhs) /= Complex(rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
  return Complex(lhs) /= Complex(rhs);
}


double modulus(const Complex& z) {
  return std::sqrt(z.re * z.re + z.im * z.im);
}

double arg(const Complex& z) {
  if (z.re == 0.0 && z.im == 0.0) {
    throw std::string("Undefined argument for zero complex number");
  }
  return std::asin(z.im / modulus(z));
}

Complex degree(const Complex& lhs, const int rhs) {
  if (lhs.im == 0.0 && lhs.re == 0.0 && rhs == 0) {
    throw std::string("Undefined zero degree for zero complex number");
  }
  if (lhs.im == 0) {
    return Complex(std::pow(lhs.re, rhs), 0.0);
  }
  double modulusZ = modulus(lhs);
  double argZ = arg(lhs);
  double newModulus = std::pow(modulusZ, rhs);
  double newArg = argZ * rhs;
  return Complex(newModulus * std::cos(newArg), newModulus * std::sin(newArg));
}

std::vector<Complex> root(const Complex& lhs, const int rhs) {
  if (rhs <= 0) {
    throw std::string("Undefined root of negative or zero degree");
  }
  std::vector<Complex> roots;
  double modulusZ = modulus(lhs);
  double argZ = arg(lhs);
  double rootModulus = std::pow(modulusZ, 1.0 / rhs);
  for (int k = 0; k < rhs; ++k) {
    double rootArg = (argZ + 2 * M_PI * k) / rhs;
    roots.push_back(Complex(rootModulus * std::cos(rootArg), rootModulus * std::sin(rootArg)));
  }
  return roots;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const noexcept {
  ostrm << leftBrace << re << separator << " " << im << rightBrace;
  return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) noexcept {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char rightBrace(0);

  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;

  if (istrm.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }

  return istrm;
}