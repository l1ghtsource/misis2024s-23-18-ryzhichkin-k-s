#pragma once

#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

class DynArr {
public:
  [[nodiscard]] DynArr() = default;
  [[nodiscard]] DynArr(const DynArr&);
  [[nodiscard]] DynArr(const ptrdiff_t size);

  ~DynArr();

  DynArr& operator=(const DynArr& rhs);

  [[nodiscard]] ptrdiff_t Size() const noexcept { return size_; }

  void Resize(const ptrdiff_t size);

  [[nodiscard]] float& operator[](const ptrdiff_t idx);
  [[nodiscard]] const float& operator[](const ptrdiff_t idx) const;

private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
  float* data_ = nullptr;
};

std::ostream& operator<<(std::ostream& out, DynArr a);

#endif