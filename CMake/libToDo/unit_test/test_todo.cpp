#include "libToDo/todo.h"

#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;
using ::testing::Test;

namespace TODO {

namespace testing {

class ToDoTest : public Test {
 protected:
  ToDoTest() {}

  ~ToDoTest() {}

  virtual void SetUp() {}

  virtual void TearDown() {}

  ToDo list;
  static const size_t task_count = 3;
  static const std::string tasks[task_count];
};

const std::string ToDoTest::tasks[task_count] = {"write_code", "compile",
                                                 "test"};

TEST_F(ToDoTest, constructor_createsEmptyList) {
  EXPECT_THAT(list.size(), Eq(size_t(0)));
}

TEST_F(ToDoTest, addTask_threeTimes_sizeIsThree) {
  list.addTask(tasks[0]);
  list.addTask(tasks[1]);
  list.addTask(tasks[2]);

  EXPECT_THAT(list.size(), Eq(task_count));
}

TEST_F(ToDoTest, getTask_withOneTask_returnsCorrentString) {
  list.addTask(tasks[0]);

  ASSERT_THAT(list.size(), Eq(size_t(1)));
  EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
}

TEST_F(ToDoTest, getTask_withThreeTasks_retunsCorrentStringForEachIndex) {
  list.addTask(tasks[0]);
  list.addTask(tasks[1]);
  list.addTask(tasks[2]);

  ASSERT_THAT(list.size(), Eq(task_count));
  EXPECT_THAT(list.getTask(0), Eq(tasks[0]));
  EXPECT_THAT(list.getTask(1), Eq(tasks[1]));
  EXPECT_THAT(list.getTask(2), Eq(tasks[2]));
}

}  // namespace testing

}  // namespace TODO
