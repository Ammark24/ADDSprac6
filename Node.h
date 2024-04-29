#ifndef NODE_H
#define NODE_H

class Node {
 private:
  int data;
  Node* link;

 public:
  Node(int value);
  int getData();
  Node* getNext();
  void setNext(Node* nextNode);
};

#endif
