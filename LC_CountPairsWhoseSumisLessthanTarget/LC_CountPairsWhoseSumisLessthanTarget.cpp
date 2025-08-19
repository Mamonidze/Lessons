
#include <iostream>
#include <vector>

int main()
{
    //Create original vector nums with length n
    std::vector<int> nums {};
    int input{};
    int n{};
    int target{};
    std::cout << "Enter vector length: \n";
    std::cin >> n;

    while (n > 0)
    {
        std::cout << "Enter an integer (" << n << " left)" << '\n';
        std::cin >> input;
        nums.push_back(input);
        n--;
    }

    std::cout << "Enter target: \n";
    std::cin >> target;

    
    int count{};
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i+1; j < nums.size(); j++)
        {
            if (i < j && nums[i] + nums[j] < target)
                count++;
        }
    }
    std::cout << count << '\n';
    
    return 0;
}