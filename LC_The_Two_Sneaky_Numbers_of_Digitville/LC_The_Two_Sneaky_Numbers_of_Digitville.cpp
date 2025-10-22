#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
        std::unordered_map<int,int> map;
        std::vector<int> result;
        for(auto i : nums)
        {
            map[i]++;
        }

        for(auto [nums, count] : map)
        {
            if(count == 2)
            {
                result.push_back(nums);
            }
        }
            
        return result;
    }
};
