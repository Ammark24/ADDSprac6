#include "Node.h"

Node::Node(int value) : data(value), link(nullptr) {}

int Node::getData() { return data; }

Node* Node::getNext() { return link; }

void Node::setNext(Node* nextNode) { link = nextNode; }
