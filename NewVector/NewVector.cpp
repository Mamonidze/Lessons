
#include <iostream>
#include <stdexcept>

class NewVector
{
private:
    int* data;
    size_t size;
    size_t capacity;
public:
    
    NewVector() //default constructor
    {
        data=nullptr;
        size=0;
        capacity=0;
        std::cout << "Default constructor" << '\n'; //DEBUG
    }

    NewVector(const size_t n) : size(n), capacity(n) //initialization list
    {
        data = new int[n]; //create new empty vector
        std::cout << "Size Constructor" << '\n'; //DEBUG
    }

    int& operator[](size_t index) //[] overload
    {
        if (index >= size)
        {
            throw std::out_of_range("Vector index out of range");
        }
        return data[index];
    }
    
    int& operator[](size_t index) const //[] const overload
    {
        if (index >= size)
        {
            throw std::out_of_range("Vector index out of range");
        }
        return data[index];
    }

    void push_back(int x)
    {
        if (size == capacity)
        {
            constexpr int multiplier{2};
            const size_t new_capacity = capacity * multiplier; // new capacity
            int* new_data = new int[new_capacity]; //new array for copying old array + 1

            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i]; //copying from old arr to new arr
            }
            delete[] data; //delete old arr
            data = new_data; // change pointer from old to new
            capacity = new_capacity; // change old capacity to new
        }
        data[size] = x; //add new element at the end of   
        size++; // increase size

        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' '; //DEBUG
        }
        std::cout << '\n';//DEBUG
    }

    void pop_back()
    {
        if (size != 0)
        {
            data[size] = 0;
            size--;

            for (size_t i = 0; i < size; ++i)
            {
                std::cout << data[i] << ' '; //DEBUG
            }
        }
    }

    void insert(size_t position, int element)
    {
        if (position > size)
        {
            throw std::out_of_range("Position is out of vector range");
        }

        if (size == capacity)
        {
            constexpr int multiplier{2};
            capacity *= multiplier;
            int* new_data = new int[capacity]; // create new array for copying
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i]; // copying from old arr to new arr
            }
            delete[] data; // delete old_arr
            data = new_data; // change pointer from old arr to new
        }
        for (size_t i = size; i > position; --i)
        {
            data[i] = data[i-1];
        }
        data[position] = element;
        size++;
        
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ' ; // DEBUG
        }
        std::cout << "Size: " << size << '\n';
        std::cout << "Capacity " << capacity << '\n';
    }

    void erase(size_t position)
    {
        if (position >= size)
        {
            throw std::out_of_range("Position is out of vector range");
        }
        for (size_t i = position; i < size-1; i++)
        {
            data[i] = data[i+1];
        }
        size--;

        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ' ;
        }
    }
    
};


int main()
{
    NewVector Vector_DefaultConstruct;
    
    NewVector Vector_SizeConstruct(10);
    
    NewVector Vector_PushBack(10);
    Vector_PushBack.push_back(1);
    
    NewVector Vector_Index(10);
    std::cout << Vector_Index[3] << '\n';
    try
    {
        std::cout << Vector_Index[50] << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    NewVector Vector_PopBack(10);
    Vector_PopBack.pop_back();

    
    NewVector Vector_Insert(10);
    try
    {
        Vector_Insert.insert(10, 1);
    }
    catch (const std::out_of_range& e)
    {
    }

    NewVector Vector_Erase(10);
    try
    {
        Vector_Erase.erase(11);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
