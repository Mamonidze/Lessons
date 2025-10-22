#include <unordered_map>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        std::unordered_map<int,int> map{};
        int count{0};
        for (int i : nums)
        {
            count += map[i];
            map[i]++;
        }
        return count;
    }
};
