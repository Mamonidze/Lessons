
#include <iostream>

class MyString
{
private:
    char* data;
    size_t size{};

    
    
public:

    MyString() // default constructor
    {
        data = nullptr;
        size = 0;
    }  

    MyString(const char* s): size(strlen(s))
    {
        data = new char[size];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = s[i];
            std::cout << data[i];
        }
    }

    MyString(size_t n, char c)
    {
        data = new char[n + 1];
        for (size_t i = 0; i < n; i++)
        {
            data[i] = c;
            std::cout << data[i];
        }
    }

    MyString(const char* s, size_t n)
    {
        data = new char[n + 1];
        for (size_t i = 0; i < n; i++)
        {
            data[i] = s[i];
            std::cout << data[i];

        }
    }
    
    char& operator[](size_t index) // [] overload
    {
        return data[index];
    }
    
    char& operator[](size_t index) const // [] overload const
    {
        return data[index];
    }
    
    MyString& operator=(const MyString& other)
    {
        if (this == &other)
        {
            return *this; //self-assignment
        }
        data = new char[other.size + 1];
        for (size_t i = 0; i < other.size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    
    friend MyString operator+(const MyString& main, const MyString& other);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    

    ~MyString()
    {
        delete[] data;
    }
    
};

std::ostream& operator<<(std::ostream& os, const MyString& str) //output
{
    for (size_t i = 0; i < str.size; ++i)
    {
        os << str.data[i];
    }
    return os;
}

MyString operator+(const MyString& main, const MyString& other) //concatenation
{
    MyString result;
    result.data = new char[main.size + other.size + 1];
    for (size_t i = 0; i < main.size; i++)
    {
        result[i] = main.data[i];
    }
    for (size_t i = 0; i < other.size; i++)
    {
        result[i + main.size] = other.data[i];
    }
    for (size_t i = 0; i < main.size + other.size; i++)
    {
        std::cout << result[i];
    }
    return result;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buffer[1024]; //создаем какой то типа буфер, куда можем писать до 1024 символов
    std::cin >> buffer; //пишем в буфер
    delete[] str.data; // удаляем старую строку
    str.size = strlen(buffer); //меняем сайз класса, эт важно, чтобы мусор не выдавал
    str.data = new char[str.size + 1]; //выделяем память под новую длину
    for (size_t i = 0; i < str.size; i++)
    {
        str.data[i] = buffer[i]; //пишем
    }
    return is;
}





int main()
{
    MyString s2{"Hello, Bitches"}; //copy of str
    std::cout << '\n';
    
    MyString s3(5, 's');//fill
    std::cout << '\n';
    
    MyString s4("Hello world", 5);//from sequence
    std::cout << '\n';
    
    std::cout << s4[3];//[] overload
    std::cout << '\n';
    
    MyString s5("Solid Snake");
    std::cout << '\n';
    MyString s6("Big Boss");
    s5 = s6; //= overload
    std::cout << '\n';
    
    std::cout << s6; //<< overload
    std::cout << '\n';
    
    MyString s7("Revolver Ocelot");
    s6+s7; //+overload
    std::cout << '\n';

    MyString s8("Hello, World");
    std::cout << '\n';
    std::cin >> s8; //>> overload
    std::cout << s8;

    
    
    return 0;
}
