
#include <iostream>

class Complex
{
private:
     float real{};
     float imag{};
    
public:

    Complex(const Complex& other) = default; //default copy constructor
    
    Complex(float real, float imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex& operator=(const Complex& other) =default;
    Complex& operator+=(const Complex& other)
    {
        this->real += other.real;
        this->imag += other.imag;
        return *this;
    }
    Complex& operator-=(const Complex& other)
    {
        this->real -= other.real;
        this->imag -= other.imag;
        return *this;
    }
    Complex& operator*=(const Complex& other)
    {
        float oldReal = this->real;
        this->real = oldReal * other.real - this->imag * other.imag;
        this->imag = oldReal * other.imag + this->imag * other.real;
        return *this;
    }
    Complex& operator/=(const Complex& other)
    {
        float oldReal = this->real;
        auto denom = other.real * other.real + other.imag * other.imag;
        this->real = (oldReal * other.real + this->imag * other.imag) / denom;
        this->imag = (this->imag * other.real - oldReal * other.imag) / denom;
        return *this;
    }
    
    friend Complex operator+(const Complex& main, const Complex& other);
    friend Complex operator-(const Complex& main, const Complex& other);
    friend Complex operator*(const Complex& main, const Complex& other);
    friend Complex operator/(const Complex& main, const Complex& other);
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
    friend std::istream& operator>>(std::istream& is, Complex& complex);
    //=, +, -, *, /, <<, >>, +=, -=, *=, /=

    ~Complex() = default;
};

Complex operator+(const Complex& main, const Complex& other)
{
    Complex result(main.real + other.real, main.imag + other.imag);
    return result;
}

Complex operator-(const Complex& main, const Complex& other)
{
    Complex result(main.real - other.real, main.imag - other.imag);
    return result;
}

Complex operator*(const Complex& main, const Complex& other)
{
    Complex result(main.real * other.real - main.imag * other.imag, main.real * other.imag + main.imag * other.real);
    return result;
}

Complex operator/(const Complex& main, const Complex& other)
{
    auto denom = other.real * other.real + other.imag * other.imag;
    Complex result(
         (main.real * other.real + main.imag * other.imag) / denom,
        (main.imag * other.real - main.real * other.imag) / denom);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os << "(" << complex.real << "," << complex.imag << "i" << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
    std::cin >> complex.real >> complex.imag;
    return is;
}




int main()
{
    Complex a(3,1);
    Complex b(2.3,-3.1);
    std::cout << a/b;
    a *= b;
    std::cout << a;
    return 0;
}
