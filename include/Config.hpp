#pragma once

#include <string>
using namespace std;

enum class Mode { NONE, CREATE_TASK, PRINT_ALL };

class Config {
 public:
  Config(const string data_dir);
  Config(int argc, char* argv[]);
  Config();
  string data_dir;
	Mode mode;
};
