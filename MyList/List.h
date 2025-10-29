#pragma once

template<typename T>
class List
{
    class ListNode
    {
    public:
        // у каждой ноды есть:
        T value;      // значение
        ListNode* prev; // указатель на пред ноду
        ListNode* next; // указатель на след ноду

        ListNode(const T& v) : value(v), prev(nullptr), next(nullptr){} // конструктор
        ~ListNode(); //деструктор
    };
public:
    ListNode* head{};// указатель на первый элемент
    ListNode* tail{};// указатель на последний элемент
    size_t size{};    // размер

    List(size_t size): size(size){} //конструктор
    List(size_t size, const T& value) : head {nullptr}, tail(nullptr)
    {
        for (size_t i = 0; i < size; ++i)
        {
            push_back(value);
        }
    }
    ~List(){head = nullptr; tail = nullptr; size = 0;} //деструктор

    void push_back(const T &value);
    void push_front(const T &value);
    void pop_back();
    void pop_front();
    void insert(T &value, size_t pos);
    void erase(size_t pos);

};

#include "List.hpp"