#include <stacklst/stacklst.hpp>

#include <stdexcept>

bool StackLst::IsEmpty() const noexcept {
  return (head == nullptr);
}

void StackLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
  }
}

void StackLst::Push(const Complex& v) {
  Node* g = new Node;
  g->next = head;
  g->v = v;
  head = g;
}

Complex& StackLst::Top() {
  if (!IsEmpty()) {
    return head->v;
  }
  else {
    throw std::logic_error("StackLst - try get top from empty stack.");
  }
}

const Complex& StackLst::Top() const {
  if (!IsEmpty()) {
    return head->v;
  }
  else {
    throw std::logic_error("StackLst - try get top from empty stack.");
  }
}

void StackLst::Clear() noexcept {
  Node* temp;
  while (!IsEmpty()) {
    Pop();
  }
}
