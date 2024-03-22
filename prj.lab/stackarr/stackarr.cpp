#include <stackarr/stackarr.hpp>

#include <stdexcept>

StackArr::StackArr(const StackArr& rhs)
  : size_{ rhs.size_ },
  capacity_{ rhs.capacity_ },
  data_{ new Complex[rhs.capacity_] },
  head_{ data_ + rhs.size_ - 1 } {
  std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
}

StackArr::StackArr(const Complex& rhs)
  : size_{ 1 }, 
  capacity_{ 1 }, 
  data_{ new Complex[1] }, 
  head_{ data_ } {
  *head_ = rhs;
}

StackArr::StackArr(StackArr&& rhs) noexcept
  : size_{ rhs.size_ },
  capacity_{ rhs.capacity_ },
  data_{ rhs.data_ },
  head_{ rhs.head_ } {
  rhs.data_ = nullptr;
  rhs.head_ = nullptr;
  rhs.size_ = 0;
  rhs.capacity_ = 0;
}

StackArr::~StackArr() {
  size_ = 0;
  capacity_ = 0;

  delete[] data_;
  head_ = nullptr;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
  if (this != &rhs) {
    if (capacity_ < rhs.capacity_) {
      delete[] data_;
      capacity_ = rhs.capacity_;
      data_ = new Complex[capacity_];
    }

    size_ = rhs.size_;
    std::copy(rhs.data_, rhs.data_ + size_, data_);
    head_ = data_ + size_;
  }
  return *this;
}

StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
  if (this != &rhs) {
    delete[] data_;

    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = rhs.data_;
    head_ = rhs.head_;

    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.data_ = nullptr;
    rhs.head_ = nullptr;
  }
  return *this;
}

bool StackArr::IsEmpty() const noexcept {
  return (size_ == 0);
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    size_ -= 1;
    head_ -= 1;
    if (head_ == 0) {
      head_ = nullptr;
    }
  }
}

void StackArr::Push(const Complex& val) {
  if (IsEmpty()) {
    if (capacity_ == 0) {
      data_ = new Complex[1];
    }

    size_ = 1;
    capacity_ = std::max(static_cast<ptrdiff_t>(1), capacity_);
    head_ = data_;
    *head_ = val;

    return;
  }

  if (size_ == capacity_) {
    capacity_ *= 2;

    Complex* temp = new Complex[capacity_];
    std::copy(data_, data_ + size_, temp);

    delete[] data_;
    data_ = temp;
    head_ = data_ + size_;
    size_++;
    *head_ = val;
    return;
  }

  size_++;
  head_++;
  *head_ = val;
}

Complex& StackArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return *head_;
}

const Complex& StackArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("StackArr - try get top from empty stack.");
  }
  return *head_;
}

void StackArr::Clear() noexcept {
  size_ = 0;
  head_ = nullptr;
};