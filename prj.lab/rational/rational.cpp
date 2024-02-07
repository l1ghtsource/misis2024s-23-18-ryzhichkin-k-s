#include <rational/rational.hpp>

Rational::Rational(const int64_t num) {
  num_ = num;
  den_ = 1;
}

Rational::Rational(const int64_t num, const int64_t den) {
  if (0 == den) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  num_ = num;
  den_ = den;
  simplify();
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
  return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept {
  return operator-=(Rational(rhs));
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator*=(const int64_t rhs) noexcept {
  return operator*=(Rational(rhs));
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.den_ == 0) {
    throw std::invalid_argument("Division by zero");
  }
  num_ = num_ * rhs.den_;
  den_ = den_ * rhs.num_;
  simplify();
  return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
  return operator/=(Rational(rhs));
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) += rhs;
};

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) += Rational(rhs);
};

Rational operator+(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) += Rational(rhs);
};

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) -= rhs;
};

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) -= Rational(rhs);
};

Rational operator-(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) -= Rational(rhs);
};

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  return Rational(lhs) *= rhs;
}

Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
  return Rational(lhs) *= Rational(rhs);
}

Rational operator*(const int64_t lhs, Rational& rhs) noexcept {
  return Rational(lhs) *= Rational(rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  return Rational(lhs) /= rhs;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  return Rational(lhs) /= Rational(rhs);
}

Rational operator/(const int64_t lhs, Rational& rhs) {
  return Rational(lhs) /= Rational(rhs);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << slash << den_;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) noexcept {
  int64_t numerator(0);
  char slash_(0);
  int64_t denumerator(1);
  istrm >> numerator;
  istrm.get(slash_);
  int64_t tmp = istrm.peek();
  istrm >> denumerator;
  if (!istrm || tmp > '9' || tmp < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  if (istrm.good() || istrm.eof()) {
    if (slash == slash_ && denumerator > 0) {
      *this = Rational(numerator, denumerator);
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}