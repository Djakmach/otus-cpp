#include <list_container.h>
#include <gtest/gtest.h>


class TestListContainer_Int: public ::testing::Test {
protected:
  void SetUp() {
    container.push_back(value_0);
    container.push_back(value_1);
  }
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
  ListContainer<int> container;

  // void TearDown() {
  //   delete[] container;
  // }
};

// TEST(TestListContainer_Int, create_container) {
//   // как проверить на создание?
// }


TEST_F(TestListContainer_Int, push_back) {
  // int value_0 = 0;
  // int value_1 = 1;
  // int value_2 = 2;
  // ListContainer<int> container;
  // container.push_back(value_0);
  // container.push_back(value_1);

  ASSERT_EQ(container[0], value_0);

  ASSERT_EQ(container[1], value_1);
}


// TEST(TestListContainer_Int, insert_back) {
//   // Arrange
//   SerialConteiner<int> container;
//   int value_0 = 0;
//   int value_1 = 1;

//   // Act
//   container.insert(0, value_0);
//   container.insert(1, value_1);

//   // Assert
//   ASSERT_EQ(container[0], value_0);

//   ASSERT_EQ(container[1], value_1);
// }


// TEST(TestListContainer_Int, insert_begin) {
//   int value_0 = 0;
//   int value_1 = 1;
//   SerialConteiner<int> container;

//   container.insert(0, value_0);
//   container.insert(0, value_1);


//   ASSERT_EQ(container[1], value_0);

//   ASSERT_EQ(container[0], value_1);
// }


// TEST(TestListContainer_Int, insert_middle) {
//   int value_0 = 0;
//   int value_1 = 1;
//   int value_2 = 2;
//   SerialConteiner<int> container;

//   container.insert(0, value_0);
//   container.insert(1, value_2);
//   container.insert(1, value_1);

//   ASSERT_EQ(container[1], value_1) << "container[1] equal 1";
// }

// TEST(TestListContainer_Int, erase_back) {
//   int value_0 = 0;
//   int value_1 = 1;
//   SerialConteiner<int> container;
//   container.push_back(value_0);
//   container.push_back(value_1);

//   container.erase(1);

//   ASSERT_EQ(container.get_size(), 1);
//   ASSERT_EQ(container[0], 0);
// }


// TEST(TestListContainer_Int, erase_begin) {
//   int value_0 = 0;
//   int value_1 = 1;
//   SerialConteiner<int> container;
//   container.push_back(value_0);
//   container.push_back(value_1);

//   container.erase(0);

//   ASSERT_EQ(container.get_size(), 1);
//   ASSERT_EQ(container[0], 1);
// }


// TEST(TestListContainer_Int, erase_middle) {
//   int value_0 = 0;
//   int value_1 = 1;
//   int value_2 = 2;
//   SerialConteiner<int> container;
//   container.push_back(value_0);
//   container.push_back(value_1);
//   container.push_back(value_2);

//   container.erase(1);

//   ASSERT_EQ(container.get_size(), 2);
//   ASSERT_EQ(container[0], 0);
//   ASSERT_EQ(container[1], 2);
// }


// TEST(SerialContainer_Int, get_value){
//   int value_0 = 0;
//   int value_1 = 1;
//   int value_2 = 2;
//   SerialConteiner<int> container;
//   container.push_back(value_0);
//   container.push_back(value_1);
//   container.push_back(value_2);

//   ASSERT_EQ(container.get_value(0), value_0);
//   ASSERT_EQ(container.get_value(1), value_1);
//   ASSERT_EQ(container.get_value(2), value_2);
// }

// TEST(SerialContainer_Int, get_size){
//   int value_0 = 0;
//   int value_1 = 1;
//   SerialConteiner<int> container;

//   ASSERT_EQ(container.get_size(), 0);

//   container.push_back(value_0);
//   ASSERT_EQ(container.get_size(), 1);

//   container.push_back(value_1);
//   ASSERT_EQ(container.get_size(), 2);
// }
