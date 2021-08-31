#include "Task.hpp"

#include <stdlib.h>
#include <time.h>

#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace rapidjson;
using namespace std;

Task::Task(string name, int priority)
    : name_(name), priority_(priority), state_(TaskState::TO_DO) {}

Task::Task(const string& filename) { fromFile(filename); }

Task::Task() : name_(), priority_(), state_(TaskState::TO_DO) {}

string Task::get_name() const { return name_; }

int Task::get_priority() const { return priority_; }

TaskState Task::get_state() const { return state_; }

void Task::set_name(const string name) { name_ = name; }

void Task::set_priority(const int prio) { priority_ = prio; }

void Task::set_state(const TaskState state) { state_ = state; }

string Task::toJson() const {
  StringBuffer s;
  Writer<StringBuffer> writer(s);
  writer.StartObject();
  writer.Key("name");
  writer.String(name_.c_str());
  writer.Key("priority");
  writer.Uint(priority_);
  writer.Key("state");
  writer.Uint(state_);
  writer.EndObject();
  return s.GetString();
}

void Task::writeToFile(const string& data_dir) const {
  ofstream json_file;
  json_file.open((data_dir + "/" + name_ + ".task").c_str());
  json_file << toJson();
  json_file.close();
}

void Task::fromFile(const string& file_path) {
  string line;
  ifstream task_file(file_path.c_str());
  if (task_file.is_open()) {
    // There is only one line in the json files
    getline(task_file, line);
    task_file.close();
  } else {
    std::cout << file_path << " not found!" << std::endl;
    return;
  }

  Document document;
  document.Parse(line.c_str());
  if (document.HasMember("name")) {
    if (document["name"].IsString()) {
      name_ = document["name"].GetString();
    }
  } else {
    std::cout << "Field \"name\" is not set" << std::endl;
  }
  if (document.HasMember("priority")) {
    if (document["priority"].IsUint()) {
      priority_ = document["priority"].GetUint();
    }
  } else {
    std::cout << "Field \"priority\" is not set" << std::endl;
  }
  if (document.HasMember("state")) {
    if (document["state"].IsUint()) {
      state_ = static_cast<TaskState>(document["state"].GetUint());
    }
  } else {
    std::cout << "Field \"state\" is not set" << std::endl;
  }
}

void Task::print() const {
  std::cout << "name: " << name_ << "\t"
            << " priority: " << priority_ << "\t"
            << "state: " << state_ << std::endl;
}
