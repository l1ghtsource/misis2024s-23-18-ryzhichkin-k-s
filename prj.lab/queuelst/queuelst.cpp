#include <complex/complex.hpp>
#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

struct QueueLst::Node {
  Complex v;
  Node* next = nullptr;
};

bool QueueLst::IsEmpty() const noexcept {
  return (tail == nullptr);
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    if (head == tail) {
      tail = nullptr;
      head = nullptr;
    }
    else {
      Node* temp = head;
      head = head->next;
      delete temp;
      temp = nullptr;
    }
  }
}

void QueueLst::Push(const Complex& v) {
  if (IsEmpty()) {
    Node* g = new Node;
    g->next = tail;
    g->v = v;
    tail = g;
    head = tail;
  }
  else {
    Node* g = new Node;
    g->next = tail;
    g->v = v;
    tail = g;
  }
}

Complex& QueueLst::Top() {
  if (!IsEmpty()) {
    return tail->v;
  }
  else {
    throw std::logic_error("QueueLst - try get top from empty lst.");
  }
}

const Complex& QueueLst::Top() const {
  if (!IsEmpty()) {
    return tail->v;
  }
  else {
    throw std::logic_error("QueueLst - try get top from empty lst.");
  }
}

void QueueLst::Clear() noexcept {
  Node* temp;
  while (!IsEmpty()) {
    temp = tail;
    tail = tail->next;
    delete temp;
    temp = nullptr;
  }
}
