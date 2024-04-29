#include <iostream>

#include "LinkedList.h"

int main() {
  int array[5] = {5, 2, 7, 10, 0};  // Sample input array
  LinkedList list(array, 4);        // Initialize list with array elements

  char cmd;
  int pos, value;
  while (std::cin >> cmd >> pos >> value) {
    if (cmd == 'I') {
      list.insertPosition(pos, value);
    } else if (cmd == 'D') {
      list.deletePosition(pos);
    } else if (cmd == 'G') {
      std::cout << list.get(pos) << " ";
      list.printList();
    } else if (cmd == 'S') {
      int index = list.search(value);
      std::cout << index << std::endl;
    }
  }

  return 0;
}
