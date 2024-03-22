#pragma once

#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <complex/complex.hpp>

#include <cstddef>

class StackLst {
public:
  StackLst() = default;
  StackLst(const StackLst& rhs);
  StackLst(StackLst&& rhs) noexcept;

  ~StackLst() = default;

  StackLst& operator=(const StackLst& rhs);
  StackLst& operator=(StackLst&& rhs) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  Complex& Top();
  const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex data;
    Node* next = nullptr;
    Node(Complex v) : data(v), next(nullptr) {}
  };
  Node* head = nullptr;
};

#endif