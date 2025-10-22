#include <unordered_map>

class Solution {
public:
    int countKDifference(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map{};
        int counter{0};
        for(auto i : nums)
        {
            counter += map[i+k] + map[i-k];
            map[i]++;
        }
        return counter;
    }
};
