#include <iostream>

#include "Serializer.hpp"
using namespace std;

class Task : Serializer {
 public:
  Task(string name, int priority);
  Task();

  string get_name();
  int get_priority();

  string toJson();
  void writeToFile(const string& files_path);
  void fromFile(const string& files_path);

 private:
  string name_;
  int priority_;
};

