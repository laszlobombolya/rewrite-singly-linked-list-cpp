#pragma once

#include <exception>

class SinglyLinkedList {
 private:
  class Link {
   public:
    Link(int value) : value(value) {};

    int getValue() const;

    Link *getNext() const;

    void setNext(Link *link);

   private:
    const int value;
    SinglyLinkedList::Link *next;

  };

  Link *head;

 public:
  /**
   * Add a new element to the list.
   * The new element is appended to the current last item.
   *
   * @param value value to be appended
   */
  void add(int value);

  /**
   * Get a value based on its index.
   *
   * @param index the position of requested value
   * @return value of element at index
   */
  int get(int index) const;

  /**
   * Returns the zero-based index of the first occurrence of a value in the list.
   *
   * @param number value to be searched
   * @return Index of 'number' if it's in the list, otherwise -1;
   */
  int indexOf(int number) const;

  /**
   * Inserts a value at an index into the array shifting elements if necessary.
   *
   * @param index  Position of the new element
   * @param number Value to be inserted.
   */
  void insert(int index, int number);

  /**
   * Returns with the amount of inserted nodes.
   *
   * @return Size of list.
   */
  int size() const;

  /**
   * Removes the element at 'index' from the array.
   *
   * @param index Position of value to be deleted.
   */
  void remove(int index);
};
