#include <queuelstpr/queuelstpr.hpp>

#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {
  Node* curr = rhs.head;
  while (curr) {
    Push(curr->data);
    curr = curr->next;
  }
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept : head(rhs.head), tail(rhs.tail) {
  rhs.head = nullptr;
  rhs.tail = nullptr;
}

QueueLstPr::~QueueLstPr() {
  Clear();
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
  if (this == &rhs) {
    return *this;
  }
  Clear();
  Node* curr = rhs.head;
  while (curr) {
    Push(curr->data);
    curr = curr->next;
  }
  return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept {
  if (this != &rhs) {
    Clear();
    head = rhs.head;
    tail = rhs.tail;
    rhs.head = nullptr;
    rhs.tail = nullptr;
  }
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
  return head == nullptr;
}

void QueueLstPr::Pop() noexcept {
  if (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) {
      tail = nullptr;
    }
  }
}

void QueueLstPr::Push(const float& val) {
  Node* newNode = new Node(val);
  if (!head) {
    head = newNode;
    tail = newNode;
  }
  else if (val < head->data) {
    newNode->next = head;
    head = newNode;
  }
  else {
    Node* current = head;
    while (current->next && val >= current->next->data) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (!newNode->next) {
      tail = newNode;
    }
  }
}

float& QueueLstPr::Top() {
  if (head) {
    return head->data;
  }
  throw std::out_of_range("Queuelstpr - try get top from empty queue.");
}

const float& QueueLstPr::Top() const {
  if (head) {
    return head->data;
  }
  throw std::out_of_range("Queuelstpr - try get top from empty queue.");
}

void QueueLstPr::Clear() noexcept {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
}