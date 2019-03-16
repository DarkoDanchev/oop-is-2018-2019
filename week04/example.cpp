#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
  char name[32];
  int age;
  bool gender; //true is male
  char birthDate[11];
  char address[64];
public:
  Person()
  {
    strcpy(name,"Jon Snow");
    age = 18;
    gender = true;
    strcpy(birthDate,"10/10/1010");
    strcpy(address,"Winter Fall");
  }
  Person(const char* name, int age,bool gender,const char* birthDate,const char* address)
  {
    strcpy(this->name,name);
    this->age = age;
    this->gender = gender;
    strcpy(this->birthDate,birthDate);
    strcpy(this->address,address);
  }

  void setName(const char* name)
  {
    strcpy(this->name,name);
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setGender(bool gender)
  {
    this->gender = gender;
  }
  void setBirthDate(const char* birthDate)
  {
    strcpy(this->birthDate,birthDate);
  }
  void setAddress(const char* address)
  {
    strcpy(this->address,address);
  }

  const char* getName() const
  {
    return this->name;
  }
  int getAge() const
  {
    return this->age;
  }

  bool getGender() const
  {
    return this->gender;
  }

  const char* getBirthDate() const
  {
    return this->birthDate;
  }

  const char* getAddress() const
  {
    return this->address;
  }

  void print() const
  {
    cout<<this->name<<endl;
    cout<<this->age<<endl;
    cout<<boolalpha<<this->gender<<endl;
    cout<<this->birthDate<<endl;
    cout<<this->address<<endl;
  }

};

class Person2
{
private:
  char name[32];
  int age;
  bool gender; //true is male
  char birthDate[11];
  char address[64];
public:
  Person2()
  {
    strcpy(name,"Jon Snow");
    age = 18;
    gender = true;
    strcpy(birthDate,"10/10/1010");
    strcpy(address,"Winter Fall");
  }
  Person2(const char* name, int age,bool gender,const char* birthDate,const char* address)
  {
    strcpy(this->name,name);
    this->age = age;
    this->gender = gender;
    strcpy(this->birthDate,birthDate);
    strcpy(this->address,address);
  }

  void setName(const char* name)
  {
    strcpy(this->name,name);
  }
  void setAge(int age)
  {
    this->age = age;
  }
  void setGender(bool gender)
  {
    this->gender = gender;
  }
  void setBirthDate(const char* birthDate)
  {
    strcpy(this->birthDate,birthDate);
  }
  void setAddress(const char* address)
  {
    strcpy(this->address,address);
  }

  const char* getName() const
  {
    return this->name;
  }
  int getAge() const
  {
    return this->age;
  }

  bool getGender() const
  {
    return this->gender;
  }

  const char* getBirthDate() const
  {
    return this->birthDate;
  }

  const char* getAddress() const
  {
    return this->address;
  }

  void print() const
  {
    cout<<this->name<<endl;
    cout<<this->age<<endl;
    cout<<boolalpha<<this->gender<<endl;
    cout<<this->birthDate<<endl;
    cout<<this->address<<endl;
  }

};

class Earth
{
private:
  Person humanity[256];
  size_t numberOfPersons;
public:
  Earth()
  {
    this->numberOfPersons = 2;
    Person jonSnow;
    Person danaerys = Person("Danaerys Targerian",18,false,"10/10/1010","Not Westeros");
    this->humanity[0] = jonSnow;
    this->humanity[1] = danaerys;
  }
  void addPersonToHumanity(Person person)
  {
    this->humanity[this->numberOfPersons++] = person;
  }

  void removeLastPerson()
  {
    this->numberOfPersons--;
  }

  void print() const
  {
    for(int i = 0; i < this->numberOfPersons; i++)
    {
      this->humanity[i].print();
    }
  }

  int populationSize() const
  {
    return this->numberOfPersons;
  }

};
int main()
{
  Person jon;
  //jon.print();
  Person darko("Darko",22,true,"22/11/1996","Macedonia Forever");

  Earth earth;
  earth.print();
  earth.addPersonToHumanity(darko);
  earth.print();
  return 0;
}
