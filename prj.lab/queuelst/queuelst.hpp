#pragma once

#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <cstddef>

struct Complex;

class QueueLst {
public:
  [[nodiscard]] QueueLst() = default;
  [[nodiscard]] QueueLst(const QueueLst&) = default;

  ~QueueLst() = default;

  [[nodiscard]] QueueLst& operator=(const QueueLst&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);

  [[nodiscard]] Complex& Top();
  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node;
  Node* head = nullptr;
  Node* tail = nullptr;
};

#endif