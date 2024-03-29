#pragma once

#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <complex/complex.hpp>

#include <cstddef>

class QueueArr {
public:
  QueueArr() = default;
  QueueArr(const QueueArr& rhs);
  QueueArr(const Complex& rhs);
  QueueArr(QueueArr&& rhs) noexcept;

  ~QueueArr();

  QueueArr& operator=(const QueueArr& rhs);
  QueueArr& operator=(QueueArr&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

private:
  Complex* data_ = nullptr;
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t head_ = 0;
  std::ptrdiff_t tail_ = 0;
};

#endif