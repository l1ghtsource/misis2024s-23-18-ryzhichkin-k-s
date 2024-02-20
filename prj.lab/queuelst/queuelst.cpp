#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

bool QueueLst::IsEmpty() const noexcept {
  return (head == nullptr);
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  else {
    tail = nullptr;
  }
}

void QueueLst::Push(const Complex& v) {
  Node* g = new Node(v);
  if (IsEmpty()) {
    head = tail = g;
  }
  else {
    tail->next = g;
    tail = tail->next;
  }
}

Complex& QueueLst::Top() {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::logic_error("Queuelst - try get top from empty queue.");
  }
}

const Complex& QueueLst::Top() const {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::logic_error("Queuelst - try get top from empty queue.");
  }
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}