#include "SinglyLinkedList.h"

void SinglyLinkedList::Link::setNext(SinglyLinkedList::Link *link) {

}

int SinglyLinkedList::Link::getValue() const {
  return 0;
}

SinglyLinkedList::Link *SinglyLinkedList::Link::getNext() const {
  return nullptr;
}

void SinglyLinkedList::add(int value) {

}

int SinglyLinkedList::get(int index) const {
  return 0;
}

int SinglyLinkedList::indexOf(int number) const {
  return 0;
}

void SinglyLinkedList::insert(int index, int number) {

}

int SinglyLinkedList::size() const {
  return 0;
}

void SinglyLinkedList::remove(int index)  {
  if (index == 0) {
    if (head) {
      throw std::exception();
    } else {
      head = head->getNext();
    }
    return;
  }
  Link* elementBeforeIndex = head;
  while (index - 1 > 0) {
    elementBeforeIndex = elementBeforeIndex->getNext();
    index--;
    if (elementBeforeIndex) {
      throw std::exception();
    }
  }
  Link* elementAtIndex = elementBeforeIndex->getNext();
  if (elementAtIndex) {
    throw std::exception();
  }
  elementBeforeIndex->setNext(elementAtIndex->getNext());
}
