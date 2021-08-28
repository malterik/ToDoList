#include "Serializer.hpp"
#include <iostream>
using namespace std;

class Task : Serializer
{
public:
   Task(string name, int priority);
   ~Task();

   string get_name();
   int get_priority();

   string toJson();
   void writeToFile(const string& files_path);

private:
   string name_;
   int priority_;
};

