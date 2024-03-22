#include <rational/rational.hpp>

Rational::Rational() : num_{ 0 }, den_{ 1 } {}

Rational::Rational(const int64_t num, const int64_t den) {
  if (0 == den) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  num_ = num;
  den_ = den;
  simplify();
}

int64_t Rational::num() const { 
  return num_; 
}

int64_t Rational::den() const { 
  return den_; 
}

Rational& Rational::operator=(const Rational& rhs) {
  if (this != &rhs) {
    num_ = rhs.num_;
    den_ = rhs.den_;
    simplify();
  }
  return *this;
}

Rational& Rational::operator=(const int64_t rhs) {
  return operator=(Rational(rhs, 1));
}

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) {
  return operator+=(Rational(rhs));
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) {
  return operator-=(Rational(rhs));
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  simplify();
  return *this;
}

Rational& Rational::operator*=(const int64_t rhs) {
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

bool operator==(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() == rhs.num() && lhs.den() == rhs.den());
}

bool operator==(const Rational& lhs, const int64_t rhs) {
  return (lhs == Rational(rhs));
}

bool operator==(const int64_t lhs, const Rational& rhs) {
  return (Rational(lhs) == rhs);
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
  return !(lhs == rhs);
}

bool operator!=(const Rational& lhs, const int64_t rhs) {
  return !(lhs == rhs);
}

bool operator!=(const int64_t lhs, const Rational& rhs) {
  return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}

bool operator<(const Rational& lhs, const int64_t rhs) {
  return (lhs < Rational(rhs));
}

bool operator<(const int64_t lhs, const Rational& rhs) {
  return (Rational(lhs) < rhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() <= rhs.num() * lhs.den());
}

bool operator<=(const Rational& lhs, const int64_t rhs) {
  return (lhs <= Rational(rhs));
}

bool operator<=(const int64_t lhs, const Rational& rhs) {
  return (Rational(lhs) <= rhs);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}

bool operator>(const Rational& lhs, const int64_t rhs) {
  return (lhs > Rational(rhs));
}

bool operator>(const int64_t lhs, const Rational& rhs) {
  return (Rational(lhs) > rhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
  return (lhs.num() * rhs.den() >= rhs.num() * lhs.den());
}

bool operator>=(const Rational& lhs, const int64_t rhs) {
  return (lhs >= Rational(rhs));
}

bool operator>=(const int64_t lhs, const Rational& rhs) {
  return (Rational(lhs) >= rhs);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  return (Rational(lhs) += rhs);
};

Rational operator+(const Rational& lhs, const int64_t rhs) {
  return (Rational(lhs) += Rational(rhs));
};

Rational operator+(const int64_t lhs, Rational& rhs) {
  return (Rational(lhs) += Rational(rhs));
};

Rational operator-(const Rational& lhs, const Rational& rhs) {
  return (Rational(lhs) -= rhs);
};

Rational operator-(const Rational& lhs, const int64_t rhs) {
  return (Rational(lhs) -= Rational(rhs));
};

Rational operator-(const int64_t lhs, Rational& rhs) {
  return (Rational(lhs) -= Rational(rhs));
};

Rational operator*(const Rational& lhs, const Rational& rhs) {
  return (Rational(lhs) *= rhs);
}

Rational operator*(const Rational& lhs, const int64_t rhs) {
  return (Rational(lhs) *= Rational(rhs));
}

Rational operator*(const int64_t lhs, Rational& rhs) {
  return (Rational(lhs) *= Rational(rhs));
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  return (Rational(lhs) /= rhs);
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  return (Rational(lhs) /= Rational(rhs));
}

Rational operator/(const int64_t lhs, Rational& rhs) {
  return (Rational(lhs) /= Rational(rhs));
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