#pragma once

#ifndef QUEUELSTSPR_HPP
#define QUEUELSTPR_HPP

#include <cstddef>

class QueueLstsPr {
public:
  QueueLstsPr() = default;
  QueueLstsPr(const QueueLstsPr&) = default;
  QueueLstsPr(QueueLstsPr&&) = default;

  ~QueueLstsPr();

  QueueLstsPr& operator=(const QueueLstsPr&) = default;
  QueueLstsPr& operator=(QueueLstsPr&&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(float val);

  [[nodiscard]] float& Top();
  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    float data;
    Node* next;
    Node(float val) : data(val), next(nullptr) {}
  };
  Node* head = nullptr;
  Node* tail = nullptr;
};

#endif