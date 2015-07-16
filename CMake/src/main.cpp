// Copyright

#include <iostream>
#include "todo.h"

using std::cerr;
using std::cout;
using std::endl;

#define EXPECT_EQUAL(test, expect) \
  equalityTest(test, expect, #test, #expect, __FILE__, __LINE__)

template <typename T1, typename T2>
int equalityTest(const T1 test_val, const T2 expected_val,
                 const char* test_name, const char* expected_name,
                 const char* fine_name, const int line_number);

int main(int argc, char* argv[]) {
  int result = 0;

  ToDo list;
  list.addTask("write code");
  list.addTask("compile");
  list.addTask("test");

  result |= EXPECT_EQUAL(list.size(), size_t(3));
  result |= EXPECT_EQUAL(list.getTask(0), "write code");
  result |= EXPECT_EQUAL(list.getTask(1), "compile");
  result |= EXPECT_EQUAL(list.getTask(2), "test");

  if (result == 0) cout << "Test passed!" << endl;

  return result;
}

template <typename T1, typename T2>
int equalityTest(const T1 test_val, const T2 expected_val,
                 const char* test_name, const char* expected_name,
                 const char* file_name, const int line_number) {
  if (test_val != expected_val) {
    cerr << file_name << ":" << line_number << ": "
         << "Expected " << test_name << " "
         << "to equal " << expected_name << " (" << expected_val << ") "
         << "but it was (" << test_val << ")" << endl;

    return 1;
  } else {
    return 0;
  }
}
