#include <cassert>
#include <fstream>

#include "Task.hpp"

bool file_exists(const std::string& name) {
  ifstream file(name.c_str());
  return file.good();
}

int main(int argc, char* argv[]) {
  Task t = Task("Test", 3);
  assert(t.get_name() == "Test");
  assert(t.get_priority() == 3);
  assert(t.toJson() == "{\"name\":\"Test\",\"priority\":3}");
  t.writeToFile("./");
  assert(file_exists("Test.task") == true);

  Task t2 = Task("Prepare Interview", 1);
  assert(t2.get_name() == "Prepare Interview");
  assert(t2.get_priority() == 1);
  assert(t2.toJson() == "{\"name\":\"Prepare Interview\",\"priority\":1}");
  t2.writeToFile("./");
  assert(file_exists("Prepare Interview.task") == true);
  return 0;
}
