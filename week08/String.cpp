#include "String.h"
 
String::String(const char* elements)
{
  this->elements = new char[strlen(elements)+ 1];
  strcpy(this->elements,elements);
}
 
String::String()
{
  this->elements = new char[1];
  strcpy(this->elements,"");
}
String::String(const String& other)
{
  this->copy(other);
}
 
String& String::operator=(const String& other)
{
  if(this != &other)
  {
    this->erase();
    this->copy(other);
  }
 
  return *this;
}
 
String::~String()
{
  this->erase();
}
 
void String::copy(const String& other)
{
  this->elements = new char[strlen(other.elements) + 1];
  strcpy(this->elements, other.elements);
}
void String::erase()
{
  delete [] this->elements;
}
 
void String::print() const
{
  cout<<this->elements<<endl;
}
