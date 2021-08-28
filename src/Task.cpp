#include "Task.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace rapidjson;

Task::Task(string name, int priority) 
   : name_(name)
   , priority_(priority)
{
   std::cout << "name: " << name_ << " prio: " << priority_  << std::endl;
}

Task::~Task()
{
}

string Task::get_name()
{
   return name_;
}

int Task::get_priority()
{
   return priority_;
}

string Task::toJson() 
{
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
