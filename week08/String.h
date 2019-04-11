#pragma once
#include <iostream>
#include <cstring>
 
using namespace std;
 
class String
{
private:
  char* elements;
  void copy(const String&);
  void erase();
public:
  String();
  String(const char*);
  String(const String&);
  String& operator=(const String&);
  size_t length() const;
  ~String();
 
  void print() const;
};
