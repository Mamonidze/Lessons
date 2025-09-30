

//class Tamagochi
    //constructor (hp, happiness)
    //destructor
    //  hp private
    //  hapiness private
    //  t.feed (hp up if less than 100%)
    //  t.play (hapiness up if less than 100%)
    //  t.sound if hapinesss == 100%
    //  each action hp and hapiness should go down
    //  hp - 10 points, happiness  - 5 points 
//class Dog : Tamagochi
//class Cat : Tamagochi
//class Fish: Tamagochi


//ам нужен базовый класс с базовым конструктором, чтобы в детях мы могли переопределять стартовые переменные
#include <iostream>

class Tamagochi
{
protected:
    int HP{}; //
    int Happiness{};
    
public:
    Tamagochi(int h , int happy): HP(h), Happiness(happy) {}
    virtual void feed(const int& n){}
    virtual void play(const int& minutes){}
    virtual void sound(){}
    virtual void DamageHP(){}
    virtual void DamageHappiness(){}
    
    void PrintInfo() const
    {
        std::cout << "HP: " << this->GetHP() << '\n';
        std::cout << "Happiness: " << this->GetHappiness() << '\n';
    }
    int GetHP() const {return HP;}
    int GetHappiness() const {return Happiness;}
    bool IsAlive{true};
    
    
    virtual ~Tamagochi(){}
};

class Cat : public Tamagochi
{
public:
    Cat() : Tamagochi(80,60){} //конструктор наследуемого класса

    void feed(const int& n) override
    {
        if (HP >= 80)
        {
            std::cout << "Your cat is already full." << '\n';
        }
        else
        {
            HP += n;
        }
    }
    
    void play(const int& minutes) override
    {
        if (Happiness >= 60)
        {
            std::cout << "Your cat is already happy." << '\n';
        }
        else
        {
            Happiness += minutes;
        }
    }

    void sound () override
    {
        if (Happiness >= 60 && HP >= 80)
        {
            std::cout << "Meow! Meow! Meow!" << '\n';
        }
        else
        {
            std::cout << "Cat isn't ready to yell. Feed or play with it!" << '\n';
        }
    }

    void DamageHP() override
    {
        this->HP -= 10;
        if (this->HP <= 0)
        {
            this->IsAlive = false;
        }
    }

    void DamageHappiness() override
    {
        this->Happiness -= 10;
        if (this->Happiness <= 0)
        {
            this->IsAlive = false;
        }
    }
};

class Dog : public Tamagochi
{
public:
    Dog() : Tamagochi(120,50){} //конструктор наследуемого класса

    void feed(const int& n) override
    {
        if (HP >= 120)
        {
            std::cout << "Your dog is already full." << '\n';
        }
        else
        {
            HP += n/2;
        }
    }
    
    void play(const int& minutes) override
    {
        if (Happiness >= 50)
        {
            std::cout << "Your dog is already happy." << '\n';
        }
        else
        {
            Happiness += minutes*2;
        }
    }

    void sound () override
    {
        if (Happiness >= 50 && HP >= 120)
        {
            std::cout << "Woof! Woof! Woof!" << '\n';
        }
        else
        {
            std::cout << "Dog isn't ready to yell. Feed or play with it!" << '\n';
        }
    }

    void DamageHP() override
    {
        this->HP -= 20;
        if (this->HP <= 0)
        {
            this->IsAlive = false;
        }
    }

    void DamageHappiness() override
    {
        this->Happiness -= 15;
        if (this->Happiness <= 0)
        {
            this->IsAlive = false;
        }
    }
};

class Fish : public Tamagochi
{
public:
    Fish() : Tamagochi(10,100){} //конструктор наследуемого класса

    void feed(const int& n) override
    {
        if (HP >= 10)
        {
            std::cout << "Your fish is already full." << '\n';
        }
        else
        {
            HP += n*2;
        }
    }
    
    void play(const int& minutes) override
    {
        if (Happiness >= 100)
        {
            std::cout << "Your fish is already happy." << '\n';
        }
        else
        {
            Happiness += minutes/4;
        }
    }

    void sound () override
    {
        if (Happiness >= 100 && HP >= 10)
        {
            std::cout << "___! ___! ___!" << '\n';
        }
        else
        {
            std::cout << "Fish isn't ready to yell. Feed or play with it!" << '\n';
        }
    }

    void DamageHP() override
    {
        this->HP -= 1;
        if (this->HP <= 0)
        {
            this->IsAlive = false;
        }
    }
    
    void DamageHappiness() override
    {
        this->Happiness -= 30;
        if (this->Happiness <= 0)
        {
            this->IsAlive = false;
        }
    }
};

int main()
{
    Tamagochi* Pet = nullptr;
    bool IsGameActive = true;
    int menu{};
    std::cout << "Choose your pet: " << '\n';
    std::cout << "1. Cat" << '\n';
    std::cout << "2. Dog" << '\n';
    std::cout << "3. Fish" << '\n';
    std::cout << "4. Exit game" << '\n';
    std::cin >> menu;

    switch (menu)
    {
    case 1:
        Pet = new Cat();
        break;
    case 2:
        Pet = new Dog();
        break;
    case 3:
        Pet = new Fish();
        break;
    case 4:
        return 0;
    default:
        std::cout << "Wrong choice!" << '\n';
    }

    
    while (IsGameActive && Pet->IsAlive) //основной игровой цикл
    {
        int Menu_Choice;
        std::cout << "Choose your option: " << '\n';
        std::cout << "1. Check your pet " << '\n';
        std::cout << "2. Feed the pet " << '\n';
        std::cout << "3. Play with the pet " << '\n';
        std::cout << "4. Make a sound!" << '\n';
        std::cout << "5. Exit game" << '\n';
        std::cin >> Menu_Choice;
        
        switch (Menu_Choice)
        {
        case 1:
            Pet->DamageHP();
            Pet->DamageHappiness();
            Pet->PrintInfo();
            break;
        case 2:
            {
                Pet->DamageHappiness();
                int amount{};
                std::cout << "Enter food amount:" << '\n';
                std::cin >> amount;
                while (amount < 0 || amount >= 100)
                {
                    std::cout << "Wrong food amount. Try again." << '\n';
                    std::cin >> amount;
                }
                Pet->feed(amount);
                Pet->PrintInfo();
                break;
            }
        case 3:
            {
                Pet->DamageHP();
                int amount{};
                std::cout << "How much time would you like to spend with your pet? (in minutes)" << '\n';
                std::cin >> amount;
                while (amount < 0 || amount >= 100)
                {
                    std::cout << "Wrong time. Try again." << '\n';
                    std::cin >> amount;
                }
                Pet->play(amount);
                Pet->PrintInfo();
                break;
            }
        case 4:
            Pet->sound();
            break;
        case 5:
            IsGameActive = false;
            break;
        default:
            std::cout << "Wrong choice!" << '\n';
        }
        if (!Pet->IsAlive)
        {
            std::cout << "You are the worst owner of all time! Please, visit your psychiatrist!";
        }
    }
    
}
