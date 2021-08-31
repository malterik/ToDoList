#pragma once
#include <iostream>

#include "Serializer.hpp"
using namespace std;

enum TaskState { TO_DO, IN_WORK, DONE };

class Task : Serializer {
 public:
  Task(string name, int priority);
  Task(const string& filename);
  Task();

  string get_name() const;
  int get_priority() const;
  TaskState get_state() const;

  void set_name(const string name);
  void set_priority(const int prio);
  void set_state(const TaskState state);

  void print() const;

  string toJson() const;
  void writeToFile(const string& files_path) const;
  void fromFile(const string& files_path);

 private:
  string name_;
  int priority_;
  TaskState state_;
};

