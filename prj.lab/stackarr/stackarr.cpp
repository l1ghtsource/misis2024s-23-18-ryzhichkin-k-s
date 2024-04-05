#include <stackarr/stackarr.hpp>

#include <stdexcept>

StackArr::StackArr(const StackArr& rhs)
  : i_top_(rhs.i_top_) {
  if (!rhs.IsEmpty()) {
    size_ = ((i_top_ + 1) / 4 + 1) * 4;
    data_ = new Complex[size_];
    std::copy(rhs.data_, rhs.data_ + i_top_ + 1, data_);
  }
}

StackArr::StackArr(StackArr&& rhs) noexcept {
  std::swap(rhs.size_, size_);
  std::swap(rhs.i_top_, i_top_);
  std::swap(rhs.data_, data_);
}

StackArr::~StackArr() {
  delete[] data_;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      Clear();
    }
    if (size_ <= rhs.i_top_) {
      size_ = (rhs.i_top_ + 4) / 4 * 4;
      Complex* buf = new Complex[size_];
      std::swap(data_, buf);
      delete[] buf;
    }
    i_top_ = rhs.i_top_;
    std::copy(rhs.data_, rhs.data_ + i_top_ + 1, data_);
  }
  return *this;
}

StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
  if (this != &rhs) {
    if (!rhs.IsEmpty()) {
      std::swap(size_, rhs.size_);
      std::swap(i_top_, rhs.i_top_);
      std::swap(data_, rhs.data_);
    }
    else {
      Clear();
    }
  }
  return *this;
}

bool StackArr::IsEmpty() const noexcept {
  return i_top_ < 0;
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    i_top_ -= 1;
  }
}

void StackArr::Push(const Complex& val) {
  if (nullptr == data_) {
    size_ = 1;
    data_ = new Complex[size_];
  }
  else if (size_ == i_top_ + 1) {
    auto buf = new Complex[size_ * 2];
    std::copy(data_, data_ + size_, buf);
    std::swap(data_, buf);
    delete[] buf;
    size_ *= 2;
  }
  data_[++i_top_] = val;
}

Complex& StackArr::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return data_[i_top_];
}

const Complex& StackArr::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return data_[i_top_];
}

void StackArr::Clear() noexcept {
  i_top_ = -1;
};