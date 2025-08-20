#include <iostream>
/*Написать функцию RoundToInt, которая для целых чисел выводит “Число и так целое”,
 *для вещественных округляет и выводит округленное, для строк выводит “Ну и что вы от меня хотите”
 */

void RoundToInt();

int main()
{
    RoundToInt();
    return 0;
}

void RoundToInt()
{
    float input;
    std::cout << "Enter a value: ";
    std::cin >> input;
    if (std::cin.fail())
    {
        std::cout << "What do you want from me?";
        return;
    }
    float result {input - static_cast<int>(input)};
    if (result == 0.00)
    {
        std::cout << "It's already an integer";
    }
    else
    if (result > 0.00)
    {
        std::cout << "Here is your rounded number: " << std::round(input) << '\n' ;
    }
}