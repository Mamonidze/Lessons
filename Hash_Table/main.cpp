#include <iostream>

#include "hash_map.h"

int main()
{
    hash_map hash_map(10);
    if (hash_map.insert(5))
    {
        std::cout << "Value inserted";
    }
    
    if (hash_map.insert(10))
    {
        std::cout << "Value inserted";
    }
    if (hash_map.find(10))
    {
        std::cout << "Value was found";
    }
    if (hash_map.find(4))
    {
        std::cout << "Value was found";
    }
    else
    {
        std::cout << "Value wasn't found";
    }
    if (hash_map.erase(5))
    {
        std::cout << "Value was erased";
    }
}
