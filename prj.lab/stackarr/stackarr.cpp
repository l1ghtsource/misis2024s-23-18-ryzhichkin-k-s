#include <algorithm>
#include <stdexcept>

#include <stackarr/stackarr.hpp>

bool StackArr::IsEmpty() const noexcept {
  return (i_top_ < 0);
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    i_top_ -= 1;
  }
}

void StackArr::Push(const Complex& val) {
  if (data_ == nullptr) {
    size_ = 8;
    data_ = new Complex[size_];
  }
  else if (size_ == i_top_ + 1) {
    auto buf = new Complex(size_ * 2);
    std::copy(data_, data_ + size_, buf);
    std::swap(data_, buf);
    delete buf;
    size_ *= 2;
  }
  data_[++i_top_] = val;
}

Complex& StackArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return data_[i_top_];
}

const Complex& StackArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return data_[i_top_];
}

void StackArr::Clear() noexcept {
  i_top_ = -1;
}