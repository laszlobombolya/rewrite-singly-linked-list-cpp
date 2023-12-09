#pragma once
#include <iostream>
#include "SinglyLinkedList.h"

class Util {
 public:
  static void feedList(int numberOfElements, SinglyLinkedList& list) {
    std::cout << "Building the linked list ... this may take a while :)\n";
    for (int i = 1; i < numberOfElements; i++) {
      list.insert(i, i);
    }
  }

  static void terminate() {
    std::cout<< "Invalid operation!\n";
    printAvailableCommands();
    std::exit(0);
  }

  static void printAvailableCommands() {
    std::cout<< "The following operations available: access, search, insert, delete\n"
     <<"You can run the application like follows:\n"
     << " access <index to access>\n"
     << "search <number to search for>\n"
     << "insert <index to insert at> <number to insert>\n"
     << "delete <index to delete at>\n";
  }
};
