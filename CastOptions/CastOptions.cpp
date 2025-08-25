/*Варианты кастов
 *У нас есть 4 каста С++ и 1 каст C-style, который лучше не юзать, т.к. он перебирает все касты,
 *пока не найдет подходящий. Дорого, долго, нафиг не надо
 * 4 всадника Кастокалипсиса:
 * 1. static_cast - конвертация во время компиляции. Самый простой и базовый способ каста
 * 2. сonst_cast - по сути, этот каст юзается для удаления константы с переменной внутри метода
 * 3. reinterpret_cast - конвертирует указатели, при этом ему ваще плевать на результат.
 * Можно сконвертить что угодно, во что угодно, но без гарантий.Всегда возвращает что то, даже мусор
 * 4. dynamic_cast - кастит в рантайме
 */


#include <assert.h>
#include <iostream>
#include <ppltasks.h>
#include <__msvc_ostream.hpp>

void print (char* str)
{
    std::cout << str;
}
void print2 (const int* a)
{
    std::cout << a;
}

int main()
{
    //static_cast
    double a{1.124};
    int b = static_cast<int>(a);

    class Main{}; //основной класс
    class Inherited : public Main{}; //класс, наследуемый от основного

    Inherited* pointer = new Inherited(); 
    Main* pointer2 = static_cast<Main*>(pointer); //кастуем вверх по иерархии - из дочки в родителя


    //dynamic_cast
    Main Parent{};
    Main* pParent;
    Inherited Child{};
    Inherited* pChild{};
    pParent = dynamic_cast<Main*>(&Child);
    

    
    //const_cast
    const char* c = "hello world";
    print(const_cast<char*>(c)); //принудительно передаем в функцию константу, хотя она принимает не конст

    int m{};
    std::cin >> m;
    print2(const_cast<int*>(&m)); //выдаем константу


    //reinterpret_cast
    int x {65};
    int* px = &x;
    char* pc = reinterpret_cast<char*>(px);
    std::cout << *pc;
    
}




