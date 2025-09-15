//каждое вводимое число храним в виде отдельного вектора
//знак числа храним отдельно в буле
//

#include <iostream>
#include <vector>

class BigInteger
{
private:
    std::vector<int> number;

public:
    BigInteger(){}
    BigInteger(const BigInteger& other);
    
    BigInteger(std::string& input)
    {
        number.reserve(input.size());
        for (size_t i = 0; i < input.length(); i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                number.push_back(input[i] - '0');
            }
        }
    }

    //=, +, -, *, /, <<, >>, +=, -=, *=, /=

    BigInteger& operator=(const BigInteger& other) = default;
    
    friend BigInteger operator+(const BigInteger& main, const BigInteger& other);
    friend BigInteger operator-(const BigInteger& main, const BigInteger& other);
    friend BigInteger operator*(const BigInteger& main, const BigInteger& other);
    friend BigInteger operator/(const BigInteger& main, const BigInteger& other);
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& BigInteger);
    friend std::istream& operator>>(std::istream& is, BigInteger& BigInteger);
    
    
};

BigInteger operator+(const BigInteger& main, const BigInteger& other)
{
    BigInteger result; //то что будем ретернить
    const std::vector<int>& a = main.number; // тут храним первый вектор
    const std::vector<int>& b = other.number; // тут второй
    std::vector<int> minimal = a.size()<=b.size() ? a : b; // тут храним минимальный вектор в который будем докидывать нули
    std::vector<int> maximum = a.size()>b.size() ? a : b; // тут храним минимальный вектор в который будем докидывать нули
    int carry{}; // тут храним остаток
    while(minimal.size() < maximum.size())
    {
        minimal.insert(minimal.begin(), 0);
    }

    for (int i = maximum.size()-1; i >= 0 || carry; i--)
    {
        if (i < 0)
        {
            result.number.push_back(carry);
            break;
        }
        int sum = maximum[i] + minimal[i] + carry;
        if (sum >= 10)
        {
            carry = 1;
            result.number.push_back(sum%10);
        }
        else
        {
            carry = 0;
            result.number.push_back(sum%10);
        }
    }
    reverse(result.number.begin(), result.number.end());
    return result;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& BigInteger)
{
    for (auto element : BigInteger.number)
    {
        os << element << ' ';
    }
    return os;
}



int main()
{
    std::string inputa{};
    std::string inputb{};
    std::cout << "Enter your numbers: ";
    std::cin >> inputa >> inputb;

    BigInteger a(inputa);
    BigInteger b(inputb);

    std::cout << a+b;
    
    return 0;
}
