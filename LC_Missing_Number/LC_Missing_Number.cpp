#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {

        int n = nums.size();
        int sum = n*(n+1)/2;
        int result{};
        for(auto it : nums)
        {
            result += it;
        }

        return sum - result;
    }
};
