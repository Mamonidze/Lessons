#include "Vector.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Vector Vector_DefaultConstruct;
    
    Vector Vector_SizeConstruct(10);
    
    Vector Vector_PushBack(10);
    Vector_PushBack.push_back(1);
    
    Vector Vector_Index(10);
    std::cout << Vector_Index[3] << '\n';
    try
    {
        std::cout << Vector_Index[50] << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    Vector Vector_PopBack(10);
    Vector_PopBack.pop_back();

    
    Vector Vector_Insert(10);
    try
    {
        Vector_Insert.insert(10, 1);
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error:  " << e.what() << '\n';
    }

    Vector Vector_Erase(10);
    try
    {
        Vector_Erase.erase(11);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }

    Vector Vector_Output(5);
    std::cout << "Vector output" << Vector_Output << '\n';

    return 0;
}
