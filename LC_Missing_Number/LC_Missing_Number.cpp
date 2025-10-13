#include <unordered_set>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());


        for(int i = 0; i <= nums.size() + 1; i++)
        {
            if(set.count(i) == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
