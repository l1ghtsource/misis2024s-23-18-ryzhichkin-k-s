#include <stackarr/stackarr.hpp>

StackArr::StackArr(const StackArr& rhs)
  : size_(rhs.size_), capacity_(rhs.size_) {
  data_ = new Complex[rhs.size_];
  for (int i = 0; i < rhs.size_; ++i) {
    *(data_ + i) = *(rhs.data_ + i);
  }
}

StackArr::~StackArr() {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (this != &rhs) {
    delete[] data_;
    size_ = rhs.size_;
    capacity_ = rhs.size_ * 2;
    data_ = new Complex[capacity_] {};
    for (int i = 0; i < rhs.size_; i += 1) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

bool StackArr::isEmpty() noexcept {
  return (size_ == 0);
}

void StackArr::Push(const Complex& elem) {
  if (size_ == capacity_) {
    capacity_ += 10;
    Complex* tmp = new Complex[capacity_];
    std::copy(data_, data_ + 10, tmp);
    delete[] data_;
    data_ = tmp;
  }
  data_[size_] = elem;
  ++size_;
}

void StackArr::Pop() noexcept {
  if (!(isEmpty())) {
    --size_;
  }
}

const Complex& StackArr::Top() {
  return data_[size_ - 1];
}

