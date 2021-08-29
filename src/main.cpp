#include <stdio.h>
#include <unistd.h>

#include "Config.hpp"
#include "Task.hpp"
#include "TaskManager.hpp"

int main(int argc, char* argv[]) {
  Config c(argc, argv);
  TaskManager tm = TaskManager::getInstance();
  tm.parseTasks(c.data_dir);
  tm.printTasks();

  return 0;
}
