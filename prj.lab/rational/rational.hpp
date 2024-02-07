#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#pragma once

#include <iosfwd>
#include <sstream>

class Rational {
public:
  Rational() = default;
  Rational(const int64_t num);
  Rational(const Rational& rhs) = default;
  Rational(const int64_t num, const int64_t den);

  Rational& operator=(const Rational&) = default;

  ~Rational() = default;

  int64_t num() const noexcept { return num_; }
  int64_t den() const noexcept { return den_; }

  Rational operator-() const noexcept { return { -num_, den_ }; }

  bool operator==(const Rational& rhs) const noexcept { return (num_ * rhs.den_ - rhs.num_ * den_) == 0; }
  bool operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }
  bool operator>(const Rational& rhs) const noexcept { return (num_ * rhs.den_ - rhs.num_ * den_) > 0; }
  bool operator<(const Rational& rhs) const noexcept { return (num_ * rhs.den_ - rhs.num_ * den_) < 0; }
  bool operator>=(const Rational& rhs) const noexcept { return (num_ * rhs.den_ - rhs.num_ * den_) >= 0; }
  bool operator<=(const Rational& rhs) const noexcept { return (num_ * rhs.den_ - rhs.num_ * den_) <= 0; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator+=(const int64_t rhs) noexcept;

  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;

  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator*=(const int64_t rhs) noexcept;

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

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator+(const int64_t lhs, Rational& rhs) noexcept;

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator-(const int64_t lhs, Rational& rhs) noexcept;

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator*(const int64_t lhs, Rational& rhs) noexcept;

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