#pragma once
#include <vector>

#include "Task.hpp"

class TaskManager {
 public:
  static TaskManager& getInstance();

  void parseTasks(const string& data_dir);
  void printTasks() const;

 private:
  TaskManager();
  std::vector<Task> task_vec_;
};

