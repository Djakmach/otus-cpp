#include <list_container.h>
#include <gtest/gtest.h>
#include <iostream>


class InitTestListContainer: public ::testing::Test {
protected:
  // void SetUp() override {}
  // void TearDown() override {}

  ListContainer<int> container;
  int value_0 = 0;
  int value_1 = 1;
  int value_2 = 2;
};


TEST_F(InitTestListContainer, IsEmptyInitially) {
  EXPECT_EQ(container.get_size(), 0);
}


TEST_F(InitTestListContainer, push_back) {
  container.push_back(value_0);
  container.push_back(value_1);
  ASSERT_EQ(container[0], value_0);
  ASSERT_EQ(container[1], value_1);
}


TEST_F(InitTestListContainer, insert_begin) {
  container.insert(0, value_1);
  container.insert(0, value_0);

  ASSERT_EQ(container[0], value_0);
  ASSERT_EQ(container[1], value_1);
}

TEST_F(InitTestListContainer, insert_back) {
  container.insert(0, value_0);
  container.insert(1, value_1);

  ASSERT_EQ(container[0], value_0);
  ASSERT_EQ(container[1], value_1);
}

TEST_F(InitTestListContainer, insert_middle) {
  container.insert(0, value_0);
  container.insert(1, value_2);
  container.insert(1, value_1);

  EXPECT_EQ(container[1], value_1);

}

TEST_F(InitTestListContainer, erase_back) {
  container.push_back(value_0);
  container.push_back(value_1);

  container.erase(1);

  ASSERT_EQ(container.get_size(), 1);
  ASSERT_EQ(container[0], 0);
}


TEST_F(InitTestListContainer, erase_begin) {
  container.push_back(value_0);
  container.push_back(value_1);

  container.erase(0);

  ASSERT_EQ(container.get_size(), 1);
  ASSERT_EQ(container[0], value_1);
}


TEST_F(InitTestListContainer, erase_middle) {
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  container.erase(1);
  
  ASSERT_EQ(container.get_size(), 2);
  ASSERT_EQ(container[0], value_0);
  ASSERT_EQ(container[1], value_2);
}


TEST_F(InitTestListContainer, get_value){
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  ASSERT_EQ(container.get_value(0), value_0);
  ASSERT_EQ(container.get_value(1), value_1);
  ASSERT_EQ(container.get_value(2), value_2);
}

TEST_F(InitTestListContainer, get_size){
  ASSERT_EQ(container.get_size(), 0);

  container.push_back(value_0);
  ASSERT_EQ(container.get_size(), 1);

  container.push_back(value_1);
  ASSERT_EQ(container.get_size(), 2);
}

TEST_F(InitTestListContainer, operator_equal) {
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  ListContainer<int> new_container = container;

  ASSERT_NE(&new_container, &container) << "new_container is old_container";
  ASSERT_EQ(container.get_size(), 3);
  ASSERT_EQ(new_container.get_size(), 3);
  ASSERT_EQ(new_container[0], container[0]);
  ASSERT_EQ(new_container[1], container[1]);
  ASSERT_EQ(new_container[2], container[2]);
}

TEST_F(InitTestListContainer, copy_constructor) {
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  ListContainer<int> new_container(container);

  ASSERT_NE(&new_container, &container) << "new_container is old_container";
  ASSERT_EQ(container.get_size(), 3);
  ASSERT_EQ(new_container.get_size(), 3);
  ASSERT_EQ(new_container[0], container[0]);
  ASSERT_EQ(new_container[1], container[1]);
  ASSERT_EQ(new_container[2], container[2]);
}

TEST_F(InitTestListContainer, move) {
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);

  ListContainer<int> new_container;
  new_container = std::move(container);

  ASSERT_EQ(container.get_size(), 0);
  ASSERT_EQ(new_container.get_size(), 3);
}

TEST_F(InitTestListContainer, move_in_not_empty_container) {
  container.push_back(value_0);
  container.push_back(value_1);
  container.push_back(value_2);
  ListContainer<int> new_container;
  new_container.push_back(value_0);

  new_container = std::move(container);

  ASSERT_EQ(container.get_size(), 0);
  ASSERT_EQ(new_container.get_size(), 3);
}