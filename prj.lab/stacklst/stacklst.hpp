#pragma once

#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <complex/complex.hpp>

#include <cstddef>

class StackLst {
public:
  StackLst() = default;
  StackLst(const StackLst&) = default;
  StackLst(StackLst&&) = default;

  ~StackLst() = default;

  StackLst& operator=(const StackLst&) = default;
  StackLst& operator=(StackLst&&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex v;
    Node* next = nullptr;
  };
  Node* head = nullptr;
};

#endif