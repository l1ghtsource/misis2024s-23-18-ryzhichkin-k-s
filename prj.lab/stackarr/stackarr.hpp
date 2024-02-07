#pragma once

#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <cstddef>

#include <complex/complex.hpp>
#include <complex/complex.cpp>

class StackArr {
public:
  [[nodiscard]] StackArr() = default;
  [[nodiscard]] StackArr(const StackArr&);

  ~StackArr();

  StackArr& operator=(const StackArr& rhs);

  bool isEmpty() noexcept;
  void Push(const Complex& elem);
  void Pop() noexcept;
  const Complex& Top();
private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
  Complex* data_ = nullptr;
};

#endif