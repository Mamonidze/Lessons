#pragma once
#include <list>
#include <vector>


template<typename T>
class hash_map
{
    
    std::vector<std::list<T>> set;
    size_t size; //количество уникальных элементов
    const int default_size{1000}; //предвыделенный вектор
    
public:
    //constructors
    hash_map();
    hash_map(size_t size);
    hash_map(const hash_map& other);

    //operators
    hash_map& operator=(const hash_map& other);

    //methods
    bool insert(const T& value);
    bool find(const T& value) const ;
    bool erase(const T& value);
    
    //destructor
    ~hash_map() = default;
};

#include "hash_map.hpp"
