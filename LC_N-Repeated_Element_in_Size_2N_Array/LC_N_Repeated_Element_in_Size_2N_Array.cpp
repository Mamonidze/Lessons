#include <unordered_map>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        std::unordered_map<int,int> map{};
        for (auto i : nums)
        {
            map[i]++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(map[nums[i]] == nums.size()/2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};
