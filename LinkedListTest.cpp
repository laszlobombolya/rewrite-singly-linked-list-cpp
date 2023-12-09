#include "gtest/gtest.h"
#include "SinglyLinkedList.h"

static void fillListWithElements(SinglyLinkedList& list){
  list.insert(0, 123);
  list.insert(1, 234);
  list.insert(2, 345);
  list.insert(3, 456);
  list.insert(4, 567);
  list.insert(5, 678);
}


GTEST_TEST(AddOne_SizeTest, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  list->add(5);
  int expected = 1;
  EXPECT_EQ(expected, list->size());
}

GTEST_TEST(AddMultiple_SizeTest, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  list->add(123);
  list->add(456);
  list->add(678);
  int expected = 3;
  EXPECT_EQ(expected, list->size());
}

GTEST_TEST(AddMultiple_ContainsValues, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  int expected_a = 123;
  int expected_b = 456;
  int expected_c = 678;
  list->add(expected_a);
  list->add(expected_b);
  list->add(expected_c);
  EXPECT_EQ(expected_a, list->get(0));
  EXPECT_EQ(expected_b, list->get(1));
  EXPECT_EQ(expected_c, list->get(2));
}

GTEST_TEST(Insert_Element_CanBeAccessed, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  int expected_a = 123;
  int expected_idx = 0;
  list->insert(expected_idx, expected_a);
  EXPECT_EQ(expected_a, list->get(expected_idx));
}

GTEST_TEST(Insert_MultipleElement_CanBeAccessed, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  int expected_a = 123;
  int expected_b = 456;
  int expected_c = 678;
  list->insert(0, expected_a);
  list->insert(1, expected_b);
  list->insert(2, expected_c);
  EXPECT_EQ(expected_a, list->get(0));
  EXPECT_EQ(expected_b, list->get(1));
  EXPECT_EQ(expected_c, list->get(2));
}

GTEST_TEST(Insert_Element_CanBeAccessed, Negative) {
  SinglyLinkedList *list = new SinglyLinkedList();

  EXPECT_THROW({
                 try {
                   list->insert(-1, 123);
                 }
                 catch (const std::exception e) {
                   EXPECT_STREQ("", e.what());
                   throw;
                 }
               }, std::exception);
}

GTEST_TEST(Insert_MultipleElement_AtFirst, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  int expected_a = 123;
  int expected_b = 456;
  int expected_c = 678;
  list->insert(0, expected_a);
  list->insert(0, expected_b);
  list->insert(0, expected_c);
  EXPECT_EQ(expected_c, list->get(0));
  EXPECT_EQ(expected_b, list->get(1));
  EXPECT_EQ(expected_a, list->get(2));
}

GTEST_TEST(Throw_OutOfBound_Index, Negative) {
  SinglyLinkedList *list = new SinglyLinkedList();
  list->add(1);
  EXPECT_THROW({
                 try {
                   list->get(10);
                 }
                 catch (const std::exception e) {
                   EXPECT_STREQ("", e.what());
                   throw;
                 }
               }, std::exception);
}

GTEST_TEST(Remove_elementFromFirstIndex, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  fillListWithElements(*list);

  list->remove(0);

  EXPECT_EQ(234, list->get(0));
  EXPECT_EQ(345, list->get(1));
}

GTEST_TEST(Remove_elementFromMiddleIndex, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  fillListWithElements(*list);

  list->remove(2);

  EXPECT_EQ(123, list->get(0));
  EXPECT_EQ(234, list->get(1));
  EXPECT_EQ(456, list->get(2));
  EXPECT_EQ(567, list->get(3));
  EXPECT_EQ(678, list->get(4));

  list->remove(3);

  EXPECT_EQ(123, list->get(0));
  EXPECT_EQ(234, list->get(1));
  EXPECT_EQ(456, list->get(2));
  EXPECT_EQ(678, list->get(3));
}

GTEST_TEST(indexOf_existingElement, Positive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  fillListWithElements(*list);

  EXPECT_EQ(0, list->indexOf(123));
  EXPECT_EQ(3, list->indexOf(456));
  EXPECT_EQ(5, list->indexOf(678));
}

GTEST_TEST(indexOf_NotInList, Negtive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  fillListWithElements(*list);

  EXPECT_EQ(-1, list->indexOf(444));
  EXPECT_EQ(-1, list->indexOf(666));
  EXPECT_EQ(-1, list->indexOf(888));
}

GTEST_TEST(size_emptyList, Negtive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  EXPECT_EQ(0, list->size());
}

GTEST_TEST(size_filledWithElements, Negtive) {
  SinglyLinkedList *list = new SinglyLinkedList();
  fillListWithElements(*list);
  EXPECT_EQ(6, list->size());
}
