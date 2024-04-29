#include "LinkedList.h"

#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
  for (int i = len - 1; i >= 0; --i) {
    insertPosition(1, array[i]);  // Insert elements at the front
  }
}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->getNext();
    delete temp;
  }
}

void LinkedList::insertPosition(int pos, int newNum) {
  if (pos < 1) pos = 1;

  Node* newNode = new Node(newNum);

  if (pos == 1) {
    newNode->setNext(head);
    head = newNode;
  } else {
    Node* current = head;
    int currPos = 1;

    while (current->getNext() != nullptr && currPos < pos - 1) {
      current = current->getNext();
      currPos++;
    }

    newNode->setNext(current->getNext());
    current->setNext(newNode);
  }
}

bool LinkedList::deletePosition(int pos) {
  if (pos < 1 || head == nullptr) return false;

  Node* current = head;
  if (pos == 1) {
    head = head->getNext();
    delete current;
    return true;
  }

  int currPos = 1;
  while (current != nullptr && currPos < pos - 1) {
    current = current->getNext();
    currPos++;
  }

  if (current == nullptr || current->getNext() == nullptr) return false;

  Node* temp = current->getNext();
  current->setNext(temp->getNext());
  delete temp;
  return true;
}

int LinkedList::get(int pos) {
  if (pos < 1) return std::numeric_limits<int>::max();

  Node* current = head;
  int currPos = 1;
  while (current != nullptr && currPos < pos) {
    current = current->getNext();
    currPos++;
  }

  if (current == nullptr) return std::numeric_limits<int>::max();
  return current->getData();
}

int LinkedList::search(int target) {
  Node* current = head;
  int index = 1;
  while (current != nullptr) {
    if (current->getData() == target) {
      return index;
    }
    current = current->getNext();
    index++;
  }
  return -1;  // Target not found
}

void LinkedList::printList() {
  Node* current = head;
  std::cout << "[";
  while (current != nullptr) {
    std::cout << current->getData();
    if (current->getNext() != nullptr) {
      std::cout << " ";
    }
    current = current->getNext();
  }
  std::cout << "]" << std::endl;
}
