#pragma once
#include <iostream>

#include "Serializer.hpp"
using namespace std;

class Task : Serializer {
 public:
  Task(string name, int priority);
  Task(const string& filename);
  Task();

  string get_name() const;
  int get_priority() const;

  string toJson();
  void writeToFile(const string& files_path) const;
  void fromFile(const string& files_path);

 private:
  string name_;
  int priority_;
};

