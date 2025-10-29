#include <iostream>
#include "hash_map.h"

int main()
{
    hash_map<int> int_map(10);
    if (int_map.insert(5))
    {
        std::cout << "Value inserted" << '\n';
    }
    if (int_map.insert(10))
    {
        std::cout << "Value inserted"<< '\n';
    }
    if (int_map.find(10))
    {
        std::cout << "Value was found"<< '\n';
    }
    if (int_map.find(4))
    {
        std::cout << "Value was found"<< '\n';
    }
    else
    {
        std::cout << "Value wasn't found"<< '\n';
    }
    if (int_map.erase(5))
    {
        std::cout << "Value was erased"<< '\n';
    }
    std::cout << "-------------------------------"<< '\n';
    std::cout << "-------------------------------"<< '\n';
    std::cout << "-------------------------------"<< '\n';
    std::cout << "-------------------------------"<< '\n';
    std::cout << "Other T:" << '\n';


    hash_map<std::string> string_map(10);
    if (string_map.insert("choo choo"))
    {
        std::cout << "Value inserted" << '\n';
    }
    if (string_map.insert("choo choo 2"))
    {
        std::cout << "Value inserted"<< '\n';
    }
    if (string_map.find("choo choo"))
    {
        std::cout << "Value was found"<< '\n';
    }
    if (string_map.find("choo choo 2"))
    {
        std::cout << "Value was found"<< '\n';
    }
    else
    {
        std::cout << "Value wasn't found"<< '\n';
    }
    if (string_map.erase("choo choo 2"))
    {
        std::cout << "Value was erased"<< '\n';
    }

    
}
