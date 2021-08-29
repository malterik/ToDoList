#include "TaskManager.hpp"

#include <experimental/filesystem>
#include <experimental/string_view>

using namespace std::literals;

namespace fs = std::experimental::filesystem;

TaskManager& TaskManager::getInstance() {
  static TaskManager tm;
  return tm;
}

TaskManager::TaskManager() : task_vec_() {}

void TaskManager::parseTasks(const string& data_dir) {
  for (const auto& entry : fs::directory_iterator(data_dir)) {
    auto filename = entry.path().string();
    // check if the file has the .task appendix
    if (!filename.substr(filename.size() - 5).compare(".task")) {
      task_vec_.emplace_back(filename);
    }
  }
}
