#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

QueueLst::QueueLst(const QueueLst& rhs) {
  Node* current = rhs.head;
  while (current != nullptr) {
    Push(current->data);
    current = current->next;
  }
}

QueueLst::QueueLst(QueueLst&& rhs) noexcept : head(rhs.head), tail(rhs.tail) {
  rhs.head = nullptr;
  rhs.tail = nullptr;
}

QueueLst::~QueueLst() {
  Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
  if (this != &rhs) {
    Clear();
    Node* current = rhs.head;
    while (current != nullptr) {
      Push(current->data);
      current = current->next;
    }
  }
  return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
  if (this != &rhs) {
    Clear();
    head = rhs.head;
    tail = rhs.tail;
    rhs.head = nullptr;
    rhs.tail = nullptr;
  }
  return *this;
}

bool QueueLst::IsEmpty() const noexcept {
  return head == nullptr;
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
      tail = nullptr;
    }
  }
}

void QueueLst::Push(const Complex& val) {
  Node* newNode = new Node(val);
  if (IsEmpty()) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

Complex& QueueLst::Top() {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::out_of_range("Queuelst - try get top from empty queue.");
  }
}

const Complex& QueueLst::Top() const {
  if (!IsEmpty()) {
    return head->data;
  }
  else {
    throw std::out_of_range("Queuelst - try get top from empty queue.");
  }
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}