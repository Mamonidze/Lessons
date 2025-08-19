#include <iostream>
#include <vector>


int main()
{
   const std::vector<std::vector<int>>& accounts{{1,6},{7,3}, {3,5}};

    int MaxWealth{};
    int Count{};

    for (size_t i = 0; i < accounts.size(); i++)
    {
        for (size_t j = 0; j < accounts[i].size(); j++)
        {
            Count += accounts[i][j];
        }
        MaxWealth = std::max(Count, MaxWealth);
        Count = 0;
    }
   std::cout << MaxWealth;
    return 0;
}

