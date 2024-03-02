#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

QueueArr::QueueArr(const QueueArr& other) : size_(other.size_), data_(new Complex[size_]), head_(other.head_), tail_(other.tail_) {
  std::copy(other.data_, other.data_ + size_, data_);
}

QueueArr::~QueueArr() {
  delete[] data_;
}

QueueArr& QueueArr::operator=(const QueueArr& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    data_ = new Complex[size_];
    std::copy(other.data_, other.data_ + size_, data_);
    head_ = other.head_;
    tail_ = other.tail_;
  }
  return *this;
}

bool QueueArr::IsEmpty() const noexcept {
  return Count() == 0;
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_ != tail_) {
      head_ = (head_ + 1) % size_;
    }
    else {
      head_ = -1;
    }
  }
}

void QueueArr::Push(const Complex& val) {
  if (nullptr == data_) {
    data_ = new Complex[1];
    size_ = 1;
    head_ = 0;
    tail_ = 0;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      std::ptrdiff_t newSize = size_ * 2;
      Complex* newData = new Complex[newSize];
      std::ptrdiff_t count = Count();
      for (std::ptrdiff_t i = 0; i < count; ++i) {
        newData[i] = data_[(head_ + i) % size_];
      }
      delete[] data_;
      data_ = newData;
      size_ = newSize;
      head_ = 0;
      tail_ = Count() - 1;
    }
    else {
      tail_ = (tail_ + 1) % size_;
    }
  }
  data_[tail_] = val;
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
  head_ = -1;
  tail_ = -1;
}

std::ptrdiff_t QueueArr::Count() const {
  if (head_ == -1 || tail_ == -1) {
    return 0;
  }
  return (tail_ - head_ + size_) % size_ + 1;
}