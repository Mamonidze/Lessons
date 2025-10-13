#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++)
        {
            if(set.find(nums[i]) != set.end())
            {
                return true;
            }
            set.emplace(nums[i]);
        }
        return false;
    }
};
