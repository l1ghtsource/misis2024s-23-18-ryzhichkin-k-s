#pragma once

#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP

#include <cstddef>

class QueueLstPr {
public:
  QueueLstPr() = default;
  QueueLstPr(const QueueLstPr& rhs);
  QueueLstPr(QueueLstPr&& rhs) noexcept;

  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr&);
  QueueLstPr& operator=(QueueLstPr&&) noexcept;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const float& val);

  float& Top();
  const float& Top() const;

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