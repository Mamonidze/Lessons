
#include <iostream>
#include <vector>
bool IsInVector(std::vector<int> &vector, int x);

int main()
{
    std::vector<int> nums1{4,9,5};
    std::vector<int> nums2 {9,4,9,8,4};
    std::vector<int> nums3 {};

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (IsInVector(nums3, nums2[j]))
            {
                continue;
            }
            if (nums1[i] == nums2[j])
            {
                nums3.push_back(nums2[j]);
            }
        }
    }
    for (int nums31 : nums3)
    {
        std::cout << nums31 << std::endl;
    }
    return 0;
}

bool IsInVector(std::vector<int> vector, int x)
{
    for (auto element : vector)
    {
        if (element == x)
        {
            return true;
        }
    }
    return false;
}
