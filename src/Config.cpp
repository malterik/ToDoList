#include "Config.hpp"

#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
namespace po = boost::program_options;

Config::Config(int argc, char* argv[]) {
  mode = Mode::NONE;
  try {
    po::options_description desc("Allowed options");
    desc.add_options()
      ("help", "produce help message")
      ("data-dir", po::value<string>(), "set directory to save tasks")
      ("create-task", "Start dialog to create a task")
      ("print-tasks", "Print a lists of all tasks");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
      cout << desc << "\n";
    }

    if (vm.count("data-dir")) {
      data_dir = vm["data-dir"].as<string>();
    } else {
      cout << "File directory was not set\n";
    }

    if (vm.count("create-task")) {
      mode = Mode::CREATE_TASK;
    }

    if (vm.count("print-tasks")) {
      mode = Mode::PRINT_ALL;
    }

  } catch (exception& e) {
    cerr << "error: " << e.what() << "\n";
  } catch (...) {
    cerr << "Exception of unknown type!\n";
  }
}

Config::Config(const string data_dir) : data_dir(data_dir), mode(Mode::NONE)  {}

Config::Config() : data_dir(), mode(Mode::NONE) {}

