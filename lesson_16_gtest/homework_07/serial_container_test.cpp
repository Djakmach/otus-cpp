#include <serial_container.h>
#include <gtest/gtest.h>


TEST(TestSerialContainer_Int, create_container) {
  // как проверить на создание?
}


TEST(TestSerialContainer_Int, push_back) {
  // Arrange
  SerialConteiner<int> container;
  int value_0 = 0;
  int value_1 = 1;

  // Act
  container.push_back(value_0);
  container.push_back(value_1);


  // Assert
  ASSERT_EQ(container[0], value_0);

  ASSERT_EQ(container[1], value_1);
}


TEST(TestSerialContainer_Int, insert_back) {
  // Arrange
  SerialConteiner<int> container;
  int value_0 = 0;
  int value_1 = 1;

  // Act
  container.insert(0, value_0);
  container.insert(1, value_1);

  // Assert
  ASSERT_EQ(container[0], value_0);

  ASSERT_EQ(container[1], value_1);
}


TEST(TestSerialContainer_Int, insert_begin) {
  int value_0 = 0;
  int value_1 = 1;
  SerialConteiner<int> container;

  container.insert(0, value_0);
  container.insert(0, value_1);


  ASSERT_EQ(container[1], value_0);

  ASSERT_EQ(container[0], value_1);
}


TEST(TestSerialContainer_Int, insert_middle) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;

  container.insert(0, value_0);
  container.insert(1, value_2);
  container.insert(1, value_1);

  ASSERT_EQ(container[1], value_1) << "container[1] equal 1";
}

TEST(TestSerialContainer_Int, erase_back) {
  int value_0 = 0;
  int value_1 = 1;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);

  container.erase(1);

  ASSERT_EQ(container.get_size(), 1);
  ASSERT_EQ(container[0], 0);
}


TEST(TestSerialContainer_Int, erase_begin) {
  int value_0 = 0;
  int value_1 = 1;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);

  container.erase(0);

  ASSERT_EQ(container.get_size(), 1);
  ASSERT_EQ(container[0], 1);
}


TEST(TestSerialContainer_Int, erase_middle) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  container.erase(1);

  ASSERT_EQ(container.get_size(), 2);
  ASSERT_EQ(container[0], 0);
  ASSERT_EQ(container[1], 2);
}


TEST(TestSerialContainer_Int, get_value){
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  ASSERT_EQ(container.get_value(0), value_0);
  ASSERT_EQ(container.get_value(1), value_1);
  ASSERT_EQ(container.get_value(2), value_2);
}

TEST(TestSerialContainer_Int, get_size){
  int value_0 = 0;
  int value_1 = 1;
  SerialConteiner<int> container;

  ASSERT_EQ(container.get_size(), 0);

  container.push_back(value_0);
  ASSERT_EQ(container.get_size(), 1);

  container.push_back(value_1);
  ASSERT_EQ(container.get_size(), 2);
}

TEST(TestSerialContainer_Int, operator_equal) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  SerialConteiner<int> new_container = container;
  
  ASSERT_NE(&new_container, &container) << "new_container is old_container";
  ASSERT_EQ(container.get_size(), 3);
  ASSERT_EQ(new_container.get_size(), 3);
  ASSERT_EQ(new_container[0], container[0]);
  ASSERT_EQ(new_container[1], container[1]);
  ASSERT_EQ(new_container[2], container[2]);
}

TEST(TestSerialContainer_Int, copy_constructor) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  SerialConteiner<int> new_container(container);

  ASSERT_NE(&new_container, &container) << "new_container is old_container";
  ASSERT_EQ(container.get_size(), 3);
  ASSERT_EQ(new_container.get_size(), 3);
  ASSERT_EQ(new_container[0], container[0]);
  ASSERT_EQ(new_container[1], container[1]);
  ASSERT_EQ(new_container[2], container[2]);
}

TEST(TestSerialContainer_Int, move) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  SerialConteiner<int> new_container;
  new_container = std::move(container);

  ASSERT_EQ(container.get_size(), 0);
  ASSERT_EQ(new_container.get_size(), 3);
}

TEST(TestSerialContainer_Int, move_in_not_empty_container) {
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  SerialConteiner<int> container;
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);
  SerialConteiner<int> new_container;
  new_container.push_back(value_0);

  new_container = std::move(container);

  ASSERT_EQ(container.get_size(), 0);
  ASSERT_EQ(new_container.get_size(), 3);
}