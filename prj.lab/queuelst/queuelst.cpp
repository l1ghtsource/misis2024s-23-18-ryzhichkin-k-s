#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

struct QueueLst::Node {
  Complex data;
  Node* next = nullptr;

  Node(Complex v) : data(v), next(nullptr) {}
};

bool QueueLst::IsEmpty() const noexcept {
  return (head == nullptr);
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Complex value = head->data;
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
    tail = g;
  }
}

Complex& QueueLst::Top() {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::logic_error("QueueLst - try get top from empty lst.");
  }
}

const Complex& QueueLst::Top() const {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::logic_error("QueueLst - try get top from empty lst.");
  }
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
