#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#pragma once

#include <iosfwd>
#include <sstream>

class Rational {
public:
  Rational();
  Rational(int64_t num) : num_{ num }, den_{ 1 } { };
  Rational(const Rational&) = default;
  Rational(Rational&&) = default;
  Rational(int64_t num, int64_t den);

  ~Rational() = default;

  Rational& operator=(const Rational& rhs);
  Rational& operator=(const int64_t rhs);
  Rational& operator=(Rational&&) = default;

  int64_t num() const;
  int64_t den() const;

  Rational operator-() const noexcept { return Rational{ -num_, den_ }; }

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs);

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs);

  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int64_t rhs);

  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs);

  std::ostream& writeTo(std::ostream& ostrm) const noexcept;
  std::istream& readFrom(std::istream& istrm) noexcept;

private:

  int64_t num_ = 0;
  int64_t den_ = 1;

  int64_t gcd(int64_t lhs, int64_t rhs) {
    int64_t a = std::max(std::abs(lhs), std::abs(rhs));
    int64_t b = std::min(std::abs(lhs), std::abs(rhs));
    return b ? gcd(b, a % b) : a;
  }

  void simplify() {
    int64_t gcd_ = gcd(std::abs(num_), std::abs(den_));
    if (den_ < 0) {
      num_ *= (-1);
      den_ *= (-1);
    }
    num_ /= gcd_;
    den_ /= gcd_;
  }

  static const char slash{ '/' };
};

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator==(const int64_t lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const int64_t rhs);

bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const int64_t rhs);
bool operator!=(const int64_t lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const int64_t rhs);
bool operator<(const int64_t lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int64_t rhs);
bool operator>(const int64_t lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int64_t rhs);
bool operator<=(const int64_t lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int64_t rhs);
bool operator>=(const int64_t lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int64_t rhs);
Rational operator+(const int64_t lhs, Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int64_t rhs);
Rational operator-(const int64_t lhs, Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int64_t rhs);
Rational operator*(const int64_t lhs, Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int64_t rhs);
Rational operator/(const int64_t lhs, Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

#endif