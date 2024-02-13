#pragma once

#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <cstddef>

#include <complex/complex.hpp>
#include <complex/complex.cpp>

class StackArr {
public:
  [[nodiscard]] StackArr() = default;

  [[nodiscard]] StackArr(const StackArr&) = default;

  ~StackArr() = default;

  [[nodiscard]] StackArr& operator=(const StackArr&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t i_top_ = -1;
  Complex* data_ = nullptr;
};

#endif