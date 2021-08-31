#include "TaskManager.hpp"

#include <algorithm>
#include <experimental/filesystem>
#include <experimental/string_view>

using namespace std::literals;

namespace fs = std::experimental::filesystem;

TaskManager& TaskManager::getInstance() {
  static TaskManager tm;
  return tm;
}

TaskManager::TaskManager() : task_vec_() {}

bool sortTaskPrio(const Task& t1, const Task& t2) {
  return t1.get_priority() > t2.get_priority();
}

void TaskManager::parseTasks(const string& data_dir) {
  for (const auto& entry : fs::directory_iterator(data_dir)) {
    auto filename = entry.path().string();
    // check if the file has the .task appendix
    if (!filename.substr(filename.size() - 5).compare(".task")) {
      task_vec_.emplace_back(filename);
    }
  }
  std::sort(task_vec_.begin(), task_vec_.end(), sortTaskPrio);
}

void TaskManager::printTasks() const {
  for (int i = 0; i < task_vec_.size(); i++) {
    std::cout << i << " ";
    task_vec_[i].print();
  }
}

void TaskManager::addTask(const Task& task) { task_vec_.push_back(task); }

void TaskManager::createTaskDialog() {
  string name;
  int prio;
  std::cout << "Enter name of Task: ";
  getline(cin, name);
  std::cout << "Enter priority of Task: ";
  cin >> prio;
  task_vec_.emplace_back(name, prio);
}

void TaskManager::saveTasks(const string& data_dir) const {
  for (const auto& task : task_vec_) {
    task.writeToFile(data_dir);
  }
}
