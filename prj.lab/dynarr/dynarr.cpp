#include <dynarr/dynarr.hpp>

DynArr::DynArr(const DynArr& rhs)
  : size_(rhs.size_), capacity_(rhs.size_), data_(std::make_unique<float[]>(rhs.size_)) {
  std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
}

DynArr::DynArr(DynArr&& other) noexcept
  : size_(other.size_), capacity_(other.capacity_), data_(std::move(other.data_)) {
  other.size_ = 0;
  other.capacity_ = 0;
}

DynArr::DynArr(const ptrdiff_t size)
  : size_(size), capacity_(size), data_(std::make_unique<float[]>(size)) {
  if (size <= 0) {
    throw std::invalid_argument("Zero size is not allowed in DynArr ctor");
  }
  std::fill(data_.get(), data_.get() + size, 0.0f);
}

DynArr::~DynArr() = default;

DynArr& DynArr::operator=(const DynArr& rhs) {
  if (this != &rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.size_ * 2;
    data_ = std::make_unique<float[]>(capacity_);
    std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
  }
  return *this;
}

DynArr& DynArr::operator=(DynArr&& rhs) noexcept {
  if (this != &rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = std::move(rhs.data_);

    rhs.size_ = 0;
    rhs.capacity_ = 0;
  }
  return *this;
}

void DynArr::Resize(const ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Negative size is not allowed in DynArr");
  }
  if (size > capacity_) {
    int new_capacity = size * 2;
    auto new_data = std::make_unique<float[]>(new_capacity);
    std::copy(data_.get(), data_.get() + size_, new_data.get());
    data_ = std::move(new_data);
    capacity_ = new_capacity;
  }
  size_ = size;
}

float& DynArr::operator[](const ptrdiff_t idx) {
  if (idx < 0 || idx >= size_) {
    throw std::invalid_argument("Index out of bounds in [] operator");
  }
  return data_[idx];
}

const float& DynArr::operator[](const ptrdiff_t idx) const {
  if (idx < 0 || idx >= size_) {
    throw std::invalid_argument("Index out of bounds in [] operator");
  }
  return data_[idx];
}

std::ostream& operator<<(std::ostream& out, const DynArr& a) {
  for (int i = 0; i < a.Size(); ++i)
    out << a[i] << " ";
  return out;
}