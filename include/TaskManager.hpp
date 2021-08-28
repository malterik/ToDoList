#pragma once
#include <vector>

#include "Task.hpp"

class TaskManager {
 public:
  TaskManager();
  void parseTasks(const string& data_dir);

 private:
  std::vector<Task> task_vec_;
};

