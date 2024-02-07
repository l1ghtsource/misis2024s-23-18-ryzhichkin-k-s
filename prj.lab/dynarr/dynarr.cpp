#include <dynarr/dynarr.hpp>

DynArr::DynArr(const DynArr& rhs)
  : size_(rhs.size_), capacity_(rhs.size_) {
  data_ = new float[rhs.size_];
  for (int i = 0; i < rhs.size_; ++i) {
    *(data_ + i) = *(rhs.data_ + i);
  }
}

DynArr::DynArr(const ptrdiff_t size)
  : size_(size), capacity_(size) {
    if (size <= 0) {
      throw std::invalid_argument("Zero size is not allowed in DynArr ctor");
    }
    data_ = new float[size] {0};
}

DynArr::~DynArr() {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
}

DynArr& DynArr::operator=(DynArr const& rhs) {
  if (this != &rhs) {
    delete[] data_;
    size_ = rhs.size_;
    capacity_ = rhs.size_ * 2;
    data_ = new float[capacity_] {};
    for (int i = 0; i < rhs.size_; i += 1) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

void DynArr::Resize(const ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Negative size is not allowed in DynArr");
  }
  if (size > capacity_) {
    int new_capacity = size * 2;
    float* new_data = new float[new_capacity] {0};
    for (int i = 0; i < size_; ++i)
      new_data[i] = data_[i];
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
  size_ = size;
}

float& DynArr::operator[](const ptrdiff_t idx) {
  if (idx < 0) {
    throw std::invalid_argument("Negative index is not allowed in [] operator");
  }
  else if (idx >= size_) {
    throw std::invalid_argument("Index that greater than size is not allowed in [] operator");
  }
  else {
    return *(data_ + idx);
  }
}

const float& DynArr::operator[](const ptrdiff_t idx) const {
  if (idx < 0) {
    throw std::invalid_argument("Negative index is not allowed in [] operator");
  }
  else if (idx >= size_) {
    throw std::invalid_argument("Index that greater than size is not allowed in [] operator");
  }
  else {
    return data_[idx];
  }
}

std::ostream& operator<<(std::ostream& out, DynArr a) {
  for (int i = 0; i < a.Size(); ++i)
    out << a[i] << " ";
  return out;
}