#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& rhs) : size_(rhs.size_), head_(0), tail_(rhs.size_) {
  data_ = new Complex[size_];
  std::copy(rhs.data_, rhs.data_ + size_, data_);
}

QueueArr::QueueArr(const Complex& rhs) : size_(1), head_(0), tail_(1) {
  data_ = new Complex[size_];
  *data_ = rhs;
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept : data_(rhs.data_), size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_) {
  rhs.data_ = nullptr;
  rhs.size_ = 0;
  rhs.head_ = 0;
  rhs.tail_ = 0;
}

QueueArr::~QueueArr() {
  Clear();
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
  if (this != &rhs) {
    delete[] data_;
    size_ = rhs.size_;
    head_ = 0;
    tail_ = rhs.size_;
    data_ = new Complex[size_];
    std::copy(rhs.data_, rhs.data_ + size_, data_);
  }
  return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
  if (this != &rhs) {
    delete[] data_;

    data_ = rhs.data_;
    size_ = rhs.size_;
    head_ = rhs.head_;
    tail_ = rhs.tail_;

    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.head_ = 0;
    rhs.tail_ = 0;
  }
  return *this;
}

bool QueueArr::IsEmpty() const noexcept {
  return (size_ == 0);
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    ++head_;
    --size_;
  }
}

void QueueArr::Push(const Complex& val) {
  if (IsEmpty()) {
    data_ = new Complex[1];
    data_[0] = val;
    size_ = 1;
    head_ = 0;
    tail_ = 1;
  }
  else {
    Complex* newData = new Complex[size_ + 1];
    std::copy(data_, data_ + size_, newData);
    delete[] data_;
    data_ = newData;
    data_[size_] = val;
    ++size_;
    ++tail_;
  }
}

Complex& QueueArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueArr - try get top from empty queue.");
  }
  return data_[head_];
}

const Complex& QueueArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueArr - try get top from empty queue.");
  }
  return data_[head_];
}

void QueueArr::Clear() noexcept {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  head_ = 0;
  tail_ = 0;
}