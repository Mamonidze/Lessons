#include <unordered_set>

class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result{};
        int count{0};
        std::unordered_set<int> set1{nums1.begin(), nums1.end()};
        std::unordered_set<int> set2{nums2.begin(), nums2.end()};
        
        for (int i = 0; i < nums1.size(); ++i)
        {
            if(set2.find(nums1[i]) != set2.end())
            {
                count++;
            }
        }
        result.push_back(count);
        count = 0;

        for (int i = 0; i < nums2.size(); ++i)
        {
            if(set1.find(nums2[i]) != set1.end())
            {
                count++;
            }
        }
        result.push_back(count);
        return result;
    }
};
