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
    BigInteger(const BigInteger& other) = default;
    
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
    
}


int main()
{
    std::vector<int> vector{};
    std::string input{};
    std::cout << "Enter your number: ";
    std::cin >> input;

    BigInteger test(input);
    
    
    return 0;
}
