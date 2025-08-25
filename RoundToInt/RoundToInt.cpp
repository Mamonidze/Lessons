#include <iostream>
/*Написать функцию RoundToInt, которая для целых чисел выводит “Число и так целое”,
 *для вещественных округляет и выводит округленное, для строк выводит “Ну и что вы от меня хотите”
 */

void RoundToInt(const int& x);
void RoundToInt(const double& x);
void RoundToInt(const std::string& x);

int main()
{
    const int a{5};
    const double b{5.49};
    const double c{5.51};
    const std::string s{"test"};
    
    RoundToInt(a);
    RoundToInt(b);
    RoundToInt(c);
    RoundToInt(s);
    return 0;
}

void RoundToInt(const int& x)
{
    std::cout << "This is already an integer!" << '\n';
}

void RoundToInt(const double& x)
{
    std::cout << "Here is your rounded double: " << std::round(x) << '\n';
}
void RoundToInt(const std::string& x)
{
    std::cout << "What do you want from me?" << '\n';
}