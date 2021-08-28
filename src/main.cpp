#include <stdio.h>
#include <unistd.h>

#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>

#include "Task.hpp"
#include "TaskManager.hpp"

namespace po = boost::program_options;

class Config {
 public:
  Config(const string data_dir);
  Config();
  string data_dir;
};

Config::Config(const string data_dir) : data_dir(data_dir) {}

Config::Config() : data_dir() {}

int arg_parse(int argc, char* argv[], Config& config) {
  try {
    po::options_description desc("Allowed options");
    desc.add_options()("help", "produce help message")(
        "data-dir", po::value<string>(), "set directory to save tasks");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
      cout << desc << "\n";
      return 0;
    }

    if (vm.count("data-dir")) {
      config.data_dir = vm["data-dir"].as<string>();
      cout << "File directory is set to " << config.data_dir << ".\n";
    } else {
      cout << "File directory was not set\n";
      return 1;
    }
  } catch (exception& e) {
    cerr << "error: " << e.what() << "\n";
    return 1;
  } catch (...) {
    cerr << "Exception of unknown type!\n";
  }
  return 0;
}

/* Task t = Task("Test", 3); */
/* Task t2 = Task(); */
/* t2.fromFile("tests/Prepare Interview.task"); */

int main(int argc, char* argv[]) {
  Config c;
  TaskManager tm;
  if (arg_parse(argc, argv, c)) {
    return 1;
  }
  tm.parseTasks(c.data_dir);

  return 0;
}
