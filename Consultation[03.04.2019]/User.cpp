#include "User.h"

User::User()
{
    strcpy(this->name, "Darko");
    this->age = 20;
    this->gender = true;
    strcpy(this->birthDate, "13/12/1999");
    strcpy(this->birthPlace, "Skopie");
    strcpy(this->address, "Vkushti");
}
User::User(const char* name,int age,bool gender,const char* birthDate,const char* birhtPlace,const char* address)
{
    strcpy(this->name, name);
    this->age = age;
    this->gender = gender;
    strcpy(this->birthDate, birthDate);
    strcpy(this->birthPlace, birthPlace);
    strcpy(this->address, address);
}
void User::setName(const char* name)
{
    strcpy(this->name, name);
}
void User::setAge(int age)
{
    this->age = age;
}

void User::setGender(bool gender)
{
    this->gender = gender;
}

void User::setBirthDate(const char* birthDate)
{
    strcpy(this->birthDate, birthDate);
}
void User::setBirthPlace(const char* birthPlace)
{
    strcpy(this->birthPlace, birthPlace);
}
void User::setAddress(const char* address)
{
    strcpy(this->address, address);
}


const char* User::  getName() const
{
    return this -> name;
}

int User:: getAge() const
{
 return this -> age;
}

bool User:: getGender() const
{
return this ->gender;

}
const char* User :: getBirthDate() const
{
return this -> birthDate;
}
const char* User:: getBirthPlace() const
{
return this->birthPlace;
}
const char* User:: getAddress() const
{
return this-> address;

}
void User:: print() const
{
cout<<"name: "<<this->name<<endl;
cout<<"age: "<<this->age <<endl;
cout<<"gender: "<<this->gender<<endl;
cout<<"birthDate: "<<this->birthDate<<endl;
cout<<"birthPlace: "<<this->birthPlace<<endl;
cout<<"address: "<<this->address<<endl;

}
