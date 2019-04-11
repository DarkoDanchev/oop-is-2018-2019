#pragma once
#include <iostream>
#include <cstring>

using namespace std;
class User
{
private:
        char name[64];
        int age;
        bool gender;//1 = male 0 = female
        char birthDate[11];
        char birthPlace[32];
        char address[64];
public:
        User();
        User(const char*,int,bool,const char*,const char*,const char*);
        void setName(const char*);
        void setAge(int);
        void setGender(bool);
        void setBirthDate(const char*);
        void setBirthPlace(const char*);
        void setAddress(const char*);
        const char* getName() const;
        int getAge() const;
        bool getGender() const;
        const char* getBirthDate() const;
        const char* getBirthPlace() const;
        const char* getAddress() const;
        void print() const;

};
