#include <queuelstspr/queuelstspr.hpp>

#include <stdexcept>

QueueLstsPr::~QueueLstsPr() {
  Clear();
}

bool QueueLstsPr::IsEmpty() const noexcept {
  return head == nullptr;
}

void QueueLstsPr::Pop() noexcept {
  if (head == nullptr) return; // Empty queue
  Node* temp = head;
  head = head->next;
  delete temp;
}

void QueueLstsPr::Push(float val) {
  Node* newNode = new Node(val);
  if (IsEmpty()) {
    head = newNode;
    tail = newNode;
  }
  else {
    if (val < head->data) {
      newNode->next = head;
      head = newNode;
    }
    else {
      Node* current = head;
      while (current->next != nullptr && val >= current->next->data) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
      if (newNode->next == nullptr) tail = newNode;
    }
  }
}

float& QueueLstsPr::Top() {
  if (IsEmpty()) throw std::out_of_range("Queue is empty");
  return head->data;
}

const float& QueueLstsPr::Top() const {
  if (IsEmpty()) throw std::out_of_range("Queue is empty");
  return head->data;
}

void QueueLstsPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}