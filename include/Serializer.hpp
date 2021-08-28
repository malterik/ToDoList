#include <iostream>
using namespace std;

class Serializer {
 public:
  virtual string toJson() = 0;
  virtual void writeToFile(const string& files_path) = 0;

 protected:
  string json_content;
};
