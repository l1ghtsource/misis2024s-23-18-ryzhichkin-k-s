#pragma once

#ifndef BITSET_HPP
#define BITSET_HPP

#include <vector>
#include <cstdint>
#include <algorithm>

class BitSet {
public:
  BitSet();
  BitSet(const BitSet& rhs);
  BitSet(BitSet&& rhs) noexcept;
  explicit BitSet(uint32_t size);

  ~BitSet();

  BitSet& operator=(const BitSet& rhs);
  BitSet& operator=(BitSet&& rhs) noexcept;

  bool operator==(const BitSet& rhs) const;
  bool operator!=(const BitSet& rhs) const;
  bool operator[](uint32_t idx) const;

  BitSet operator~() const;
  BitSet operator&(const BitSet& other) const;
  BitSet operator|(const BitSet& other) const;
  BitSet operator^(const BitSet& other) const;

  BitSet& operator&=(const BitSet& other);
  BitSet& operator|=(const BitSet& other);
  BitSet& operator^=(const BitSet& other);

  uint32_t Size() const;
  void Resize(uint32_t size);

  bool Get(uint32_t idx) const;
  void Set(uint32_t idx, bool val);

private:
  uint32_t size_ = 0;
  std::vector<uint32_t> b;
};

#endif