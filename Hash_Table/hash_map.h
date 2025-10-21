#pragma once
#include <list>
#include <vector>


/**
 * Пишем свой unordered_set 
 * конструкторы:
- вектор из листов из интов
- заранее известен размер, перевыделение только в случае плохого распределения
- конструктор
- конструктор копирования
- оператор присваивания
- деструктор
- инсерт
- файнд
- эрейз
- попробовать перевести на array
 */
class hash_map
{
    
    std::vector<std::list<int>> set;
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
    bool insert(int value);
    bool find(int value);
    bool erase(int value);
    
    //destructor
    ~hash_map() = default;
};
