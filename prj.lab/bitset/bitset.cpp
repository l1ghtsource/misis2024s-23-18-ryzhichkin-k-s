#include <bitset/bitset.hpp>

#include <stdexcept>
#include <algorithm>

BitSet::BitSet() : size_(0) {}

BitSet::BitSet(uint32_t size) : size_(size) {
  b.resize((size + 31) / 32, 0);
}

BitSet::BitSet(const BitSet& rhs) : size_(rhs.size_), b(rhs.b) {}

BitSet::BitSet(BitSet&& rhs) noexcept : size_(rhs.size_), b(std::move(rhs.b)) {
  rhs.size_ = 0;
}

BitSet::~BitSet() = default;

BitSet& BitSet::operator=(const BitSet& rhs) {
  if (this != &rhs) {
    size_ = rhs.size_;
    b = rhs.b;
  }
  return *this;
}

BitSet& BitSet::operator=(BitSet&& rhs) noexcept {
  if (this != &rhs) {
    size_ = rhs.size_;
    b = std::move(rhs.b);
    rhs.size_ = 0;
  }
  return *this;
}

bool BitSet::operator==(const BitSet& rhs) const {
  return size_ == rhs.size_ && b == rhs.b;
}

bool BitSet::operator!=(const BitSet& rhs) const {
  return !(*this == rhs);
}

bool BitSet::operator[](uint32_t idx) const {
  return Get(idx);
}

BitSet BitSet::operator~() const {
  BitSet result(*this);
  for (uint32_t i = 0; i < b.size(); ++i) {
    result.b[i] = ~result.b[i];
  }
  return result;
}

BitSet BitSet::operator&(const BitSet& other) const {
  BitSet result(std::min(size_, other.size_));
  for (uint32_t i = 0; i < result.b.size(); ++i) {
    result.b[i] = b[i] & other.b[i];
  }
  return result;
}

BitSet BitSet::operator|(const BitSet& other) const {
  BitSet result(std::max(size_, other.size_));
  for (uint32_t i = 0; i < result.b.size(); ++i) {
    if (i < b.size() && i < other.b.size()) {
      result.b[i] = b[i] | other.b[i];
    }
    else if (i < b.size()) {
      result.b[i] = b[i];
    }
    else {
      result.b[i] = other.b[i];
    }
  }
  return result;
}

BitSet BitSet::operator^(const BitSet& other) const {
  BitSet result(std::max(size_, other.size_));
  for (uint32_t i = 0; i < result.b.size(); ++i) {
    if (i < b.size() && i < other.b.size()) {
      result.b[i] = b[i] ^ other.b[i];
    }
    else if (i < b.size()) {
      result.b[i] = b[i];
    }
    else {
      result.b[i] = other.b[i];
    }
  }
  return result;
}

BitSet& BitSet::operator&=(const BitSet& other) {
  for (uint32_t i = 0; i < std::min(b.size(), other.b.size()); ++i) {
    b[i] &= other.b[i];
  }
  if (b.size() > other.b.size()) {
    b.resize(other.b.size());
  }
  return *this;
}

BitSet& BitSet::operator|=(const BitSet& other) {
  if (b.size() < other.b.size()) {
    b.resize(other.b.size());
  }
  for (uint32_t i = 0; i < other.b.size(); ++i) {
    if (i < b.size()) {
      b[i] |= other.b[i];
    }
    else {
      b.push_back(other.b[i]);
    }
  }
  return *this;
}

BitSet& BitSet::operator^=(const BitSet& other) {
  if (b.size() < other.b.size()) {
    b.resize(other.b.size());
  }
  for (uint32_t i = 0; i < other.b.size(); ++i) {
    if (i < b.size()) {
      b[i] ^= other.b[i];
    }
    else {
      b.push_back(other.b[i]);
    }
  }
  return *this;
}

uint32_t BitSet::Size() const {
  return size_;
}

void BitSet::Resize(uint32_t size) {
  size_ = size;
  b.resize((size + 31) / 32, 0);
}

bool BitSet::Get(uint32_t idx) const {
  if (idx < 0) {
    throw std::logic_error("Index should be >= 0");
  }
  if (idx >= size_) {
    throw std::logic_error("Out of range");
  }
  return (b[idx / 32] >> (idx % 32)) & 1;
}

void BitSet::Set(uint32_t idx, bool val) {
  if (idx < 0) {
    throw std::logic_error("Index should be >= 0");
  }
  if (idx >= size_) {
    if (!val) {
      throw std::logic_error("Out of range");
    }
    size_ = idx + 1;
    b.resize((size_ + 31) / 32, 0);
  }
  if (val) {
    b[idx / 32] |= (1u << (idx % 32));
  }
  else {
    b[idx / 32] &= ~(1u << (idx % 32));
  }
}