#include <vector>

class Solution {
public:
    int repeatedNTimes(std::vector<int>& nums) {
        int counter = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            counter = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    counter += 1;
                }
            }
            if (counter == nums.size()/2)
            {
                return nums[i];
            }
        }
        return counter;
    }
};
