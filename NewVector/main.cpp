#include "Vector.h"
#include <iostream>

int main()
{
    Vector<int> int_vector(10);
    int_vector.push_back(1);
    std::cout << int_vector[10] << '\n'; //must be 1

    Vector<std::string> string_vector(2);
    string_vector.push_back("char1");
    string_vector.push_back("char2");
    for (int i = 2; i < 4; ++i)
    {
        std::cout << string_vector[i] << '\n';//must be char 1; char 2
    }
    
    Vector<float> Vector_Index(10);
    std::cout << Vector_Index[3] << '\n';
    try
    {
        std::cout << Vector_Index[50] << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    string_vector.pop_back();
    
    Vector<int> Vector_Insert(10);
    try
    {
        Vector_Insert.insert(10, 1);
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error:  " << e.what() << '\n';
    }
    
    
    Vector<int> Vector_Erase(10);
    try
    {
        Vector_Erase.erase(11);
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    
    Vector<std::string> Vector_Output(1);
    Vector_Output.push_back("string 1");
    Vector_Output.push_back("string 2");
    std::cout << "Vector output" << Vector_Output << '\n';

    return 0;
}
