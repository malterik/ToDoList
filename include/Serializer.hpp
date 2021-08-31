#pragma once
#include <iostream>
using namespace std;

class Serializer {
 public:
  virtual string toJson() const = 0;
  virtual void writeToFile(const string& files_path) const = 0;
  virtual void fromFile(const string& file_path) = 0;
};
