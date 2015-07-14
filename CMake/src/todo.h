// Copyright

#ifndef _TODO_H_
#define _TODO_H_

#include <string>
#include <vector>

class ToDo {
 public:
  ToDo();

  ~ToDo();

  size_t size() const;

  void addTask(const std::string& task);

  std::string getTask(size_t index) const;

 private:
  std::vector<std::string> this_tasks;
};

#endif  // _TODO_H_
