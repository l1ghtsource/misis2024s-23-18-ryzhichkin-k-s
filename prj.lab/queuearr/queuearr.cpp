#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

std::ptrdiff_t QueueArr::Count() const {
  return IsEmpty() ? 0 : (tail_ + size_ - head_) % size_ + 1;
}

QueueArr::QueueArr(const QueueArr& rhs) {
  if (!rhs.IsEmpty()) {
    std::ptrdiff_t count = rhs.Count();
    head_ = 0;
    tail_ = count - 1;
    size_ = (count + 4) / 4 * 4;
    data_ = new Complex[size_];
    if (rhs.head_ < rhs.tail_) {
      std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.tail_ + 1, data_);
    }
    else {
      std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.size_, data_);
      std::copy(rhs.data_, rhs.data_ + rhs.tail_ + 1, data_ + rhs.size_ - rhs.head_);
    }
  }
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept {
  std::swap(size_, rhs.size_);
  std::swap(data_, rhs.data_);
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
}

QueueArr::~QueueArr() {
  delete[] data_;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
  if (this != &rhs) {
    std::ptrdiff_t count = rhs.Count();
    if (!count) {
      head_ = -1;
    }
    else {
      if (size_ < count) {
        size_ = (count + 4) / 4 * 4;
        delete[] data_;
        data_ = new Complex[size_];
      }
      if (rhs.head_ < rhs.tail_) {
        std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.tail_ + 1, data_);
      }
      else {
        std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.size_, data_);
        std::copy(rhs.data_, rhs.data_ + rhs.tail_ + 1, data_ + rhs.size_ - rhs.head_);
      }
      head_ = 0;
      tail_ = count - 1;
    }
  }
  return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
  if (this != &rhs) {
    std::swap(size_, rhs.size_);
    std::swap(data_, rhs.data_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
  }
  return *this;
}

bool QueueArr::IsEmpty() const noexcept {
  return head_ < 0;
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
  if (data_ == nullptr) {
    size_ = 2;
    data_ = new Complex[size_];
  }
  if (IsEmpty()) {
    head_ = 0;
    tail_ = 0;
  }
  else {
    if (head_ == (tail_ + 1) % size_) {
      Complex* buf = new Complex[size_ * 2];
      std::swap(buf, data_);
      if (head_ < tail_) {
        std::copy(buf + head_, buf + tail_ + 1, data_);
      }
      else {
        std::copy(buf + head_, buf + size_, data_);
        std::copy(buf, buf + tail_ + 1, data_ + tail_ - head_);
      }
      delete[] buf;
      size_ *= 2;
      tail_ = Count();
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
}