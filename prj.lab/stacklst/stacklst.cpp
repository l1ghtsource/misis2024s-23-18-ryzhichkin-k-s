#include <stacklst/stacklst.hpp>

#include <stdexcept>

StackLst::StackLst(const StackLst& rhs) {
  if (!rhs.head) {
    head = nullptr;
    return;
  }
  Node* rhsPtr = rhs.head;
  head = new Node(rhsPtr->data);
  Node* current = head;
  rhsPtr = rhsPtr->next;
  while (rhsPtr) {
    current->next = new Node(rhsPtr->data);
    current = current->next;
    rhsPtr = rhsPtr->next;
  }
}

StackLst::StackLst(StackLst&& rhs) noexcept : head(rhs.head) {
  rhs.head = nullptr;
}

StackLst& StackLst::operator=(const StackLst& rhs) {
  if (this == &rhs) {
    return *this;
  }
  Clear();
  if (!rhs.head) {
    head = nullptr;
    return *this;
  }
  Node* rhsPtr = rhs.head;
  head = new Node(rhsPtr->data);
  Node* current = head;
  rhsPtr = rhsPtr->next;
  while (rhsPtr) {
    current->next = new Node(rhsPtr->data);
    current = current->next;
    rhsPtr = rhsPtr->next;
  }
  return *this;
}

StackLst& StackLst::operator=(StackLst&& rhs) noexcept {
  if (this == &rhs) {
    return *this;
  }
  Clear();
  head = rhs.head;
  rhs.head = nullptr;
  return *this;
}

bool StackLst::IsEmpty() const noexcept {
  return head == nullptr;
}

void StackLst::Pop() noexcept {
  if (!head) {
    return;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
}

void StackLst::Push(const Complex& val) {
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

Complex& StackLst::Top() {
  if (!head) {
    throw std::logic_error("StackLst - try get top from empty stack.");
  }
  return head->data;
}

const Complex& StackLst::Top() const {
  if (!head) {
    throw std::logic_error("StackLst - try get top from empty stack.");
  }
  return head->data;
}

void StackLst::Clear() noexcept {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}