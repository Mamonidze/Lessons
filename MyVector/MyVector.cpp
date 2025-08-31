#include <iostream>
#include <vector>

class MyVector
{
private:
     int* data;//указатель на первый элемент динамического массива
    size_t size; //текущий размер динамического массива
    size_t capacity; //текущая емкость динамического массива
    
public:
    MyVector(){data = nullptr;
        size = 0;
        capacity = 0;}//дефолтный конструктор

    
    MyVector(const size_t n) : size(n), capacity(n) //конструктор по размеру со списком инициализации
    {
        data = new int[n]; //выделяем память для динамического массива по указателю
        for (size_t i = 0; i < n; i++) 
        {
            data[i] = 0; //заполняем нулями
            std::cout << data[i] << ' ';
        }
    }
    

    int& operator[](size_t index) //перегрузка оператора []
    {
        return data[index];
    }
    int& operator[](size_t index) const //перегрузка оператора []
    {
        return data[index];
    }

    

    
    void push_back(int element)
    {
        if (size == capacity)
        {
            int* new_data;
            size_t new_capacity = capacity * 2; // новый капасити
            
            new_data = new int[new_capacity]; //создаем новый массив в который будем копировать с капасити х2
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i]; //копируем все элементы из старого массива в новый
            }
            delete[] data; //удаляем старый массив
            data = new_data; // меняем указатель на новый
            capacity = new_capacity; // меняем старую капасити на новую
        }
        data[size] = element; //загоняем в последний индекс массива новый элемент  
        size++; // увеличиваем размер

        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ';
        }
    }

    
    void pop_back()
    {
        if (size != 0)
        {
            data[size] = 0;
            size--;

            for (size_t i = 0; i < size; ++i)
            {
                std::cout << data[i] << ' ';
            }
        }
    }

    
    void insert(size_t position, int element)
    {
        if (position > size)
        {
            std::cout << "Position out of range";
        }

        if (size == capacity || position >= capacity)
        {
            int* new_data;

            size_t new_capacity = capacity * 2;
            new_data = new int[new_capacity]; //создаем новый массив в который будем копировать с капасити х2
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i]; //копируем все элементы из старого массива в новый
            }
            delete[] data; //удаляем старый массив
            data = new_data; // меняем указатель на новый
            capacity = new_capacity; // меняем старую капасити на новую
        }
        for (int i = size; i > position; --i)
        {
            data[i] = data[i-1];
        }
        data[position] = element;
        size++;
        
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ' ;
        }
    }

    
    void erase(size_t position)
    {
        if (position >= size)
        {
            return;
        }
        for (size_t i = position; i < size-1; i++)
        {
            data[i] = data[i+1];
        }
        size--;

        for (size_t i = 0; i < size; ++i)
        {
            std::cout << data[i] << ' ' ;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MyVector& vec);
    
    ~MyVector() {delete[] data;
    } //дефолтный деструктор. Не забываем очищать память через delete
};


 std::ostream& operator<<(std::ostream& os, const MyVector& vec)
 {
     for (size_t i = 0; i < vec.size; ++i)
     {
         os << vec.data[i] << ' ';
     }
     return os;
}




int main()
{
    //проверка дефолтного конструктора
    MyVector Vector;

    // проверка конструктора с размером
    MyVector Vector2(10);
    MyVector Vector3(2);
    MyVector Vector4(5);
    
    //проверка перегрузки оператора []
    std::cout << Vector2[3] << '\n';
    Vector2[3] = 3;
    std::cout << Vector2[3] << '\n';

    //проверка push_back
    Vector3.push_back(5);
    std::cout << '\n';

    //проверка pop_back
    Vector3.pop_back();
    std::cout << '\n';

    //проверка insert
    Vector4.insert(3,7);
    std::cout << '\n';

    Vector4.insert(7,3);
    std::cout << '\n';
    
    //проверка erase
    Vector4.erase(3);
    std::cout << '\n';

    std::cout << "Eto vector 2 " << Vector2 << '\n';
    //тут вызываются деструкторы
    return 0; 
    
}
