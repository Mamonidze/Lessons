
#include <iostream>
#include <string>
#include <vector>

int main()
{
    const std::vector<int> nums {4,3,2,1};
    std::vector<size_t> minimals{};
    
    
    for(size_t i = 0;i < nums.size();i++)
    {
        if(i % 10 == nums[i])
        {
            minimals.push_back(i);
        }
    }
    if (!minimals.empty())
    {
        auto min = std::min_element(minimals.begin(), minimals.end());
        std::cout << *min;
    }
    else
    {
        std::cout << -1;
    }
    return 0;
}
