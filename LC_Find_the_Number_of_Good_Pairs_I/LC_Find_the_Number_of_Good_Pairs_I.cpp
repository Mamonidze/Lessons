#include <unordered_map>

class Solution {
public:
    int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::unordered_map<int, int> map{};
        int counter{0};

        for (int i = 0; i < nums2.size(); ++i)
        {
            map[i] = nums2[i] * k;
        }

        for(auto i : nums1)
        {
            for(auto& [key, value] : map)
            {
                if (i % value == 0)
                {
                    counter++;
                }    
            }
        }
        return counter;
    }
};
