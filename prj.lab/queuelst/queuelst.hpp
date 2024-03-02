#pragma once

#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <complex/complex.hpp>

#include <cstddef>

class QueueLst {
public:
  QueueLst() = default;
  QueueLst(const QueueLst&) = default;
  QueueLst(QueueLst&&) = default;

  ~QueueLst() = default;

  QueueLst& operator=(const QueueLst&) = default;
  QueueLst& operator=(QueueLst&&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex data;
    Node* next = nullptr;
    Node(Complex v) : data(v), next(nullptr) {}
  };
  Node* head = nullptr;
  Node* tail = nullptr;
};

#endif