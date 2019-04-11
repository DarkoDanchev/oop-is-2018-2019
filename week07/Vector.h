#include <iostream>

using namespace std;

class Vector
{
private:
  int* elements;
  size_t numberOfElements; //unsigned int
  size_t capacity;
  void copy(const Vector&);
  void erase();
  void resize();
public:
  Vector();
  Vector(const Vector&);
  Vector& operator=(const Vector&);
  ~Vector();
  //push(index)
  void push(size_t element,size_t index)
  {
    this->numberOfElements++;
    if (this->numberOfElements >= this->capacity)
    {
      this->resize();
    }
    for(size_t i = numberOfElements -1; i > index;i--)
    {
      this->elements[i] = this->elements[i-1];
    }

    this->elements[index] = element;
  }
  //pop(index)
  void pop(size_t index)
  {
    for(size_t i = index;i < this->numberOfElements;i++)
    {
      this->elements[i] = this->elements[i+1];
    }
    this->numberOfElements--;
  }
  //push_back
  void push_back(size_t element)
  {
    this->push(element,this->numberOfElements);
  }
  //pop_back
  void pop_back()
  {
    this->pop(this->numberOfElements - 1);
  }
  //push_front
  void push_front(size_t element)
  {
    this->push(element,0);
  }
  //pop_front
  void pop_front()
  {
    this->pop(0);
  }
  //get(index)
  int get(size_t index) const
  {
    return this->elements[index];
  }
  //empty()
  bool empty() const
  {
    return this->numberOfElements == 0;
  }
  //size()
  size_t size() const
  {
    return this->numberOfElements;
  }
  //print
  void print() const
  {
    for(size_t i = 0; i < this->numberOfElements; i++)
    {
      cout<<this->elements[i]<<endl;
    }
  }

  Vector operator+(const Vector& other)
  {
    Vector returnedVector;
    returnedVector.numberOfElements = this->numberOfElements + other.numberOfElements;
    returnedVector.capacity = this->capacity + other.capacity;
    returnedVector.elements = new int[returnedVector.capacity];

    for(size_t i = 0; i < this->numberOfElements; i++)
    {
      returnedVector.elements[i] = this->elements[i];
    }
    for(size_t i = this->size(), k = 0; i < returnedVector.size(); i++, k++)
    {
      returnedVector.elements[i] = other.elements[k];
    }

    return returnedVector;
  }

  Vector& operator+=(const Vector& other)
  {
    Vector temp = *this;
    *this = (temp + other);

    return *this;
  }

  bool operator<=(const Vector& other)
  {
    return this->size() <= other.size();
  }

  bool operator>(const Vector& other)
  {
    if(this->size() == other.size())
    {
      for(size_t i = 0 ; i < this->size(); i++)
      {
        if(this->elements[i] > other.elements[i])
        {
          return true;
        }
        else if(this->elements[i] < other.elements[i])
        {
          return false;
        }
      }
      return false;
    }
    return this->size() > other.size();
  }

  Vector& operator+=(size_t element)
  {
    this->push_back(element);
    return *this;
  }

  Vector operator+(size_t element)
  {
    Vector a = *this;
    a+=element;
    return a;
  }

  //operator+ a + b -> c[a + b]
  //operator+= a+=b -> a[a + b] *, *=, -, -=, /, /=
  //operator> return a.size() > b.size();
  //operator<= return a.size() <= b.size();
};

Vector::Vector()
{
  this->capacity = 8;
  this->numberOfElements = 0;
  this->elements = new int[this->capacity];
}
Vector::Vector(const Vector& other)
{
  this->copy(other);
}
Vector& Vector::operator=(const Vector& other)
{
  if(this != &other)
  {
    this->erase();
    this->copy(other);
  }

  return *this;
}

void Vector::copy(const Vector& other)
{
  this->elements = new int[other.capacity];
  this->capacity = other.capacity;
  this->numberOfElements = other.numberOfElements;

  for(size_t i = 0; i < this->numberOfElements; i++)
  {
    this->elements[i] = other.elements[i];
  }
}

void Vector::erase()
{
  delete [] this->elements;
}

void Vector::resize()
{
  this->capacity *= 2;
  int* newElements = new int[this->capacity];
  for(size_t i = 0; i < this->numberOfElements; i++)
  {
    newElements[i] = this->elements[i];
  }
  this->erase();
  this->elements = newElements;
}

Vector::~Vector()
{
  this->erase();
}
