#include <iostream>
#include "SinglyLinkedList.h"
#include "Util.hpp"

int main() {
  std::cout << "Your implementation is correct when there's no failing test after running mvn clean test.\n";

  int numberOfElements = 5;
  std::string command;
  std::cout << "Enter one of the following command: access, search, insert, delete\n";
  std::cin >> command;

  SinglyLinkedList* list = new SinglyLinkedList();
  std::cout << "After you're done try these to get a feel for computational cost.\n";

  Util::feedList(numberOfElements, *list);

  long start = 0, end = 0;
  if ("access" == command) {
    std::cout << "Give me a value from the list between 1-5\n";
    int value;
    std::cin >> value;

    list->get(value);
  } else if ("search" == command) {
    std::cout << "Give me an index between 0-4\n";
    int index;
    std::cin >> index;

    list->indexOf(index);

  } else if ("insert" == command) {
    std::cout << "Give me an index where to insert\n";
    int index;
    std::cin >> index;
    std::cout << "Give me value to insert\n";
    int value;
    std::cin >> value;

    list->insert(index, value);

  } else if ("delete" == command) {
    std::cout << "Give me an index between 0-4\n";
    int index;
    std::cin >> index;
    list->remove(index);

  } else {
    Util::terminate();
  }
}
