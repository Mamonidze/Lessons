
#include <iostream>
#include <vector>


/*Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i]
 *and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.*/

std::vector<int> getConcatenation(std::vector<int>& nums);

int main()
{
    //Create original vector nums with length n
    std::vector<int> original_nums {};
    int input{};
    int n{};
    std::cout << "Enter vector length: \n";
    std::cin >> n;

    while (n > 0)
    {
        std::cout << "Enter an integer (" << n << " left)" << '\n';
        std::cin >> input;
        original_nums.push_back(input);
        n--;
    }

    //output concatenated vector to the console 
    for (auto original_num : getConcatenation(original_nums))
    {
        std::cout << original_num << '\n';
    }

    return 0;
}

//concatenation fuction
std::vector<int> getConcatenation(std::vector<int>& nums)
{
    std::vector<int> newVector{};
    newVector.reserve(nums.size()*2); //reserve capacity since we know a length of the future vector

    for (auto num : nums) //could be a while loop, but not sure if it's better
    {
        newVector.push_back(num);
    }
    for (auto num : nums)
    {
        newVector.push_back(num);
    }
    
    return newVector;
}