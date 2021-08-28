#include "Task.hpp"

#include <stdlib.h>
#include <time.h>

#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace rapidjson;
using namespace std;

Task::Task(string name, int priority) : name_(name), priority_(priority) {
  std::cout << "name: " << name_ << " prio: " << priority_ << std::endl;
}

Task::Task() : name_(), priority_() {}

string Task::get_name() { return name_; }

int Task::get_priority() { return priority_; }

string Task::toJson() {
  StringBuffer s;
  Writer<StringBuffer> writer(s);
  writer.StartObject();
  writer.Key("name");
  writer.String(name_.c_str());
  writer.Key("priority");
  writer.Uint(priority_);
  writer.EndObject();
  json_content = s.GetString();
  return json_content;
}

void Task::writeToFile(const string& files_path) {
  ofstream json_file;
  json_file.open((files_path + name_ + ".task").c_str());
  json_file << json_content;
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
}

