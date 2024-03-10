#include <queuelstpr/queuelstpr.hpp>

#include <stdexcept>

QueueLstPr::~QueueLstPr() {
  Clear();
}

bool QueueLstPr::IsEmpty() const noexcept {
  return head == nullptr;
}

void QueueLstPr::Pop() noexcept {
  if (head == nullptr) return;
  Node* temp = head;
  head = head->next;
  delete temp;
}

void QueueLstPr::Push(float val) {
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

float& QueueLstPr::Top() {
  if (IsEmpty()) throw std::out_of_range("Queue is empty");
  return head->data;
}

const float& QueueLstPr::Top() const {
  if (IsEmpty()) throw std::out_of_range("Queue is empty");
  return head->data;
}

void QueueLstPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}