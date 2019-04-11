#pragma once
#include "User.h"
class SocialNetwork
{
private:
   User* users;
   size_t size;
   size_t capacity;
   void erase()
   {
        delete[] users;
   }
   void copy(const SocialNetwork& other)
   {
        this->users = new User[other.capacity];
        for(size_t i = 0;i<other.size;i++)
        {
            this->users[i] = other.users[i];
        }
        this->size = other.size;
        this->capacity = other.capacity;
   }
   void resize()
   {
        this->capacity = 2 * this->capacity + 1;
        User* temp = new User[this->capacity];
        for(size_t i = 0; i < this->size;i++)
        {
            temp[i] = this->users[i];
        }
        this->erase();
        this->users = temp;
   }
public:
    SocialNetwork()
    {
        this->capacity = 8;
        this->size = 0;
        this->users = new User[this->capacity];
    }
    SocialNetwork(const SocialNetwork& other)
    {
        this->copy(other);
    }
    SocialNetwork& operator=(const SocialNetwork& other)
    {
        if (this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    ~SocialNetwork()
    {
        this->erase();
    }
    //TODO: implement functionality
    void addUser();
    void removeUser();
};
