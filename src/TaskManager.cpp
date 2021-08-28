#include "TaskManager.hpp"

#include <experimental/filesystem>
#include <experimental/string_view>

using namespace std::literals;

namespace fs = std::experimental::filesystem;

TaskManager::TaskManager() : task_vec_() {}

void TaskManager::parseTasks(const string& data_dir) {
  std::vector<string> file_list;
  for (const auto& entry : fs::directory_iterator(data_dir)) {
    /* std::cout << std::experimental::string_view(entry.path().string()) */
    /*                  .ends_with(".task") */
    /*           << std::endl; */
  }
}