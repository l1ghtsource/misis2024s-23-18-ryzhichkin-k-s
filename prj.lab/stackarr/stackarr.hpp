#pragma once

#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <complex/complex.hpp>

#include <cstddef>

class StackArr {
public:
  StackArr() = default;
  StackArr(const StackArr& rhs);
  StackArr(StackArr&& rhs) noexcept;
  StackArr(const Complex& rhs);

  ~StackArr();

  StackArr& operator=(const StackArr& rhs);
  StackArr& operator=(StackArr&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  Complex* data_ = nullptr;
  Complex* head_ = nullptr;
};

#endif