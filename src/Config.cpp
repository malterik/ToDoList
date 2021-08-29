#include "Config.hpp"

#include <boost/program_options.hpp>
#include <iostream>
#include <iterator>
namespace po = boost::program_options;

Config::Config(int argc, char* argv[]) {
  try {
    po::options_description desc("Allowed options");
    desc.add_options()("help", "produce help message")(
        "data-dir", po::value<string>(), "set directory to save tasks");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
      cout << desc << "\n";
    }

    if (vm.count("data-dir")) {
      data_dir = vm["data-dir"].as<string>();
      cout << "File directory is set to " << data_dir << ".\n";
    } else {
      cout << "File directory was not set\n";
    }
  } catch (exception& e) {
    cerr << "error: " << e.what() << "\n";
  } catch (...) {
    cerr << "Exception of unknown type!\n";
  }
}

Config::Config(const string data_dir) : data_dir(data_dir) {}

Config::Config() : data_dir() {}

