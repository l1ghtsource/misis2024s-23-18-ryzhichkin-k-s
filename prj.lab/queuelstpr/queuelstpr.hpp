#pragma once

#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <cstddef>

class QueueLstPr {
public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr&) = default;
  QueueLstPr(QueueLstPr&&) = default;

  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr&) = default;
  QueueLstPr& operator=(QueueLstPr&&) = default;

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