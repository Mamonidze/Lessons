
#include <iostream>

class Shape
{
protected:
    virtual double CountPerimeter() = 0;
    virtual double CountArea() = 0;
    
public:
    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    constexpr static double PI = 3.14159265358979323846;
    double radius{};
    
public:
    Circle(double radius) : radius(radius) {}
    double CountArea() override
    {
        return PI * radius * radius;
    }
    
    double CountPerimeter() override
    {
        return PI * 2 * radius;
    }
};

class Triangle : public Shape
{
private:
    double side1{};
    double side2{};
    double side3{};
    
    
public:
    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3){}

    double CountPerimeter() override
    {
        return side1 + side2 + side3;
    }

    double CountArea() override
    {
        double p = this->CountPerimeter()/2;
        return sqrt(p * (p-side1) * (p - side2) * (p - side3));
    }
    
};

class Rectangle : public Shape
{
private:
    double side1{};
    double side2{};
    
public:
    Rectangle(double a, double b) : side1(a), side2(b) {}
    
    double CountArea() override
    {
        return side1 * side2;
    }

    double CountPerimeter() override
    {
        return (side1 + side2) * 2;
    }
};

int main()
{
    //проверка круга
    double r;
    std::cout << "Please enter the radius of the circle: " << '\n';
    std::cin >> r;
    Circle First_Circle (r);
    std::cout << First_Circle.CountArea() << '\n';
    std::cout << First_Circle.CountPerimeter() << '\n';
    
    //проверка треугольника
    double t1{};
    double t2{};
    double t3{};
    std::cout << "Please enter three sides of the triangle: " << '\n';
    std::cin >> t1 >> t2 >> t3;
    Triangle First_Triangle (t1, t2, t3);
    std::cout << First_Triangle.CountArea() << '\n';
    std::cout << First_Triangle.CountPerimeter() << '\n';

    double r1{};
    double r2{};
    
    std::cout << "Please enter two sides of the rectangle: " << '\n';
    std::cin >> r1 >> r2;
    Rectangle First_Rectangle (r1,r2);
    std::cout << First_Rectangle.CountArea() << '\n';
    std::cout << First_Rectangle.CountPerimeter() << '\n';


    
    
    return 0;
}
