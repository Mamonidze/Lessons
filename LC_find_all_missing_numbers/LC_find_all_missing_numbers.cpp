#include <unordered_set>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {

        std::vector<int> v{};
        std::unordered_set<int> s{nums.begin(), nums.end()};

        for(int i = 1; i <= nums.size(); i++)
        {
            if(s.find(i) == s.end())
            {
                v.push_back(i);
            }
        } 
        return v;
    }

};
