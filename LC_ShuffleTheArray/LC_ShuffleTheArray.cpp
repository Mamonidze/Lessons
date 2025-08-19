#include <iostream>
#include <vector>

std::vector<int> Shuffle(const std::vector<int>& nums, const int n);
int main()
{
    std::vector<int> nums{};
    int n{};
    int input{};
    std::cout << "Enter array length: " << '\n';
    std::cin >> n;
    int VectorCapacity{n*2};
    nums.reserve(VectorCapacity);
    std::cout << "Enter array elements (2x Array Length): " << '\n';
    while (VectorCapacity > 0)
    {
        std::cin >> input;
        nums.push_back(input);
        VectorCapacity--;
    }

    for (auto num : Shuffle(nums,n))
    {
        std::cout << num << ' ';
    }
    
    return 0;
}

std::vector<int> Shuffle(const std::vector<int>& nums, const int n)
{
    std::vector<int> ShuffledVector{};
    for (int i = 0; i < n; i++)
    {
        ShuffledVector.push_back(nums[i]);
        ShuffledVector.push_back(nums[i + n]);
    }
    return ShuffledVector;
}