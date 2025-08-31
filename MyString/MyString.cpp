
#include <iostream>

class MyString
{
private:
    char* data; //указатель на динамический массив
    size_t length{};

    
    
public:

    MyString() { std::cout << "Default constructor" << '\n';}  //default constructor

    MyString(const char* s)
    {
        
    }
    






    
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
