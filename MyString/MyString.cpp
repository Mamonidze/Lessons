
#include <iostream>

class MyString
{
private:
    char* data;
    
public:

    MyString() { std::cout << "Default constructor" << '\n';}  //default constructor

    






    
    char& operator[](size_t index) //перегрузка оператора []
    {
        return data[index];
    }

    ~MyString()
    {
        delete[] data;
    }
    
};



int main()
{
    MyString s{"Hello"};
    for (int i = 0; i < 4; ++i)
    {
        std::cout << s[i];
    }
    
    return 0;
}
