#pragma once
#include <iostream>


template<typename T>
class Vector
{
    T* data;
    size_t size;
    size_t capacity;
public:
    Vector(); //default constructor
    Vector(const size_t n);

    T& operator[](size_t index);
    T& operator[](size_t index) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);
    
    void push_back(const T& x);
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);

    ~Vector();
};

#include "Vector.hpp"