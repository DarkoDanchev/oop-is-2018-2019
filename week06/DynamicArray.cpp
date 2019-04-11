#include <iostream>
#include <vector>

using namespace std;

//Integer Dynanic array
class DynamicArray
{
private:
    int* elements;
    size_t size;
    size_t capacity;

    void resize()
    {
        int* tempElements = new int[2*this->capacity + 1];
        this->capacity = 2*this->capacity + 1;
        for(size_t i = 0; i < this->size; i++)
        {
            tempElements[i] = this->elements[i];
        }
        delete [] this->elements;
        this->elements = tempElements;
    }
public:
    DynamicArray()
    {
        this->size = 0;
        this->capacity = 8;
        this->elements = new int[this->capacity];
    }
    void push_back(int element)
    {
        if(this->size == this->capacity)
        {
            this->resize();
        }
        this->elements[this->size] = element;
        this->size++;
    }
    void pop_back()
    {

    }

    size_t getSize() const
    {
        return this->size;
    }

    int get(size_t index) const
    {
        return this->elements[index];
    }
    ~DynamicArray()
    {
        delete [] this->elements;
    }
};

int main()
{
    DynamicArray arr;
    for(size_t i = 0; i < 16; i++)
    {
        arr.push_back(i);
    }
    for(size_t i = 0; i < arr.getSize(); i++)
    {
        cout<<arr.get(i)<<endl;
    }
    return 0;
}
