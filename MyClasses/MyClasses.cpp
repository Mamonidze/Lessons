#include <iostream>
#include <vector>

class MyVector
{
private:
    int* data; //указатель на первый элемент динамического массива
    size_t size;
    size_t capacity;
    
public:
    MyVector() { std::cout << "Default constructor" << '\n';}//дефолтный конструктор
    
    MyVector(size_t n) : size(n), capacity(n) //конструктор по размеру со списком инициализации
    {
        
        data = new int[n]; //выделяем память для динамического массива по указателю
        size = n;
        for (size_t i = 0; i < n; i++) 
        {
            data[i] = 0; //заполняем нулями
        }
        std::cout << "N based constructor" << '\n';
    }

    int& operator[](size_t index)
    {
        return data[index];
    }

    void push_back(int element)
    {
        
    }
    

    
    
    ~MyVector() {delete[] data;} //дефолтный деструктор. Не забываем очищать память через delete
};


int main()
{
    std::vector<int> myvector(10,0);
    myvector.push_back(3);
    for (int i = 0; i < myvector.size(); ++i)
    {
        std::cout << myvector[i] << '\n';
    }
    
    MyVector Vector;
    MyVector Vector2(10);
    std::cout << Vector2[3] << '\n';
    Vector2[3] = 4;
    std::cout << Vector2[3] << '\n';
    
}
