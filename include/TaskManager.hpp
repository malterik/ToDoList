#pragma once
#include <vector>

#include "Task.hpp"

class TaskManager {
 public:
  static TaskManager& getInstance();

  void parseTasks(const string& data_dir);
  void printTasks() const;
  void saveTasks(const string& data_dir) const;
  void addTask(const Task& task);
  void createTaskDialog();

 private:
  TaskManager();
  std::vector<Task> task_vec_;
};
