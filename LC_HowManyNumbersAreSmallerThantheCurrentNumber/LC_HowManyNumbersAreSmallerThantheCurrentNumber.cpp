#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int> newV = nums;
    std::sort(newV.begin(),newV.end());
    std::map<int,int> map;
    
    for (int i = 0; i < newV.size(); i++) {
        if (!map.count(newV[i])) {
            map[newV[i]] = i;
        }
    }

        std::vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        result[i] = map[nums[i]];
    }

    return result;
}
};
