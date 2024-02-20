#pragma once

#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <complex/complex.hpp>

#include <cstddef>

class StackLst {
public:
  [[nodiscard]] StackLst() = default;
  [[nodiscard]] StackLst(const StackLst&) = default;

  ~StackLst() = default;

  [[nodiscard]] StackLst& operator=(const StackLst&) = default;

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