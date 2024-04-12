#pragma once

#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <memory>

class DynArr {
public:
  DynArr() = default;
  DynArr(const DynArr&);
  DynArr(DynArr&&) noexcept;
  DynArr(const ptrdiff_t size);

  ~DynArr();

  DynArr& operator=(const DynArr& rhs);
  DynArr& operator=(DynArr&& rhs) noexcept;

  ptrdiff_t Size() const noexcept { return size_; }

  void Resize(const ptrdiff_t size);

  float& operator[](const ptrdiff_t idx);
  const float& operator[](const ptrdiff_t idx) const;

private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
  std::unique_ptr<float[]> data_ = 0;
};

std::ostream& operator<<(std::ostream& out, DynArr a);

#endif