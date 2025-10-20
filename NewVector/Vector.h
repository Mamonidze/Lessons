#pragma once
#include <iostream>

class Vector
{
    int* data;
    size_t size;
    size_t capacity;
public:
    Vector(); //default constructor
    Vector(const size_t n);

    int& operator[](size_t index);
    int& operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    
    void push_back(int x);
    void pop_back();
    void insert(size_t position, int element);
    void erase(size_t position);

    ~Vector();
};
