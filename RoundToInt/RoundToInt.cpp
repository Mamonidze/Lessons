#include <iostream>
#include <vector>
/*Написать функцию RoundToInt, которая для целых чисел выводит “Число и так целое”,
 *для вещественных округляет и выводит округленное, для строк выводит “Ну и что вы от меня хотите”
 */


void RoundToInt(const int& input);
void RoundToInt(const float& input);
void RoundToInt(const std::string& input);

int main()
{
    int a {5};
    float b {5.34f};
    std::string input {"Check this out"};
    
    RoundToInt(a);
    RoundToInt(b);
    RoundToInt(input);
    return 0;
}





void RoundToInt(const int& input)
{
    std::cout << "Number " << input << " is already an integer.\n";
}


void RoundToInt(const float& input)
{
    std::cout << "Here is your rounded number: " << std::round(input) << '\n';
}

void RoundToInt(const std::string& input)
{
    std::cout << "What to you want from me?";
}


