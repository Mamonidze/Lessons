#include "hash_map.h"


hash_map::hash_map() : size(0)
{
    set.reserve(default_size);
}

hash_map::hash_map(size_t size):size(size)
{
    set.resize(size);
}

hash_map::hash_map(const hash_map& other)
{
    this->size = other.size;
    this->set  = other.set;
}

hash_map& hash_map::operator=(const hash_map& other)
{
    if (this == &other)
    {
        return *this; //self-assignment
    }
    this->size = other.size;
    this->set = other.set;
    return *this;
}

bool hash_map::insert(int value)
{
    std::hash<int> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    std::list<int>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) //если такое значение есть - фолс
        {
            return false;
        }
    }
    
    l.push_back(value); //если значения нет - пушбек в лист, size++ , тру
    size++;
    return true;
}

bool hash_map::find(int value) const
{
    std::hash<int> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    std::list<int>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) 
        {
            return true;
        }
    }
    return false;
}

bool hash_map::erase(int value)
{
    std::hash<int> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    std::list<int>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) 
        {
            set[index].erase(it);
            return true;
        }
    }
    return false;
}








