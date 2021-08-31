#include <stdio.h>
#include <unistd.h>

#include "Config.hpp"
#include "Task.hpp"
#include "TaskManager.hpp"

int main(int argc, char* argv[]) {
  Config c(argc, argv);
  TaskManager tm = TaskManager::getInstance();
  tm.parseTasks(c.data_dir);

  switch (c.mode) {
    case Mode::CREATE_TASK:
      tm.createTaskDialog();
      tm.printTasks();
      break;
    case Mode::PRINT_ALL:
      tm.printTasks();
      break;
    default:
      std::cout << "Unknown operation!" << std::endl;
      break;
  }

  tm.saveTasks(c.data_dir);
  return 0;
}
