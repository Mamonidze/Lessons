#include <iterator>
#include <map>
#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::map<int,int> map;
        for(int i : nums)
        {
            map[i]++;
        }

        int i = std::prev(map.end())->first;
        map[i]--;
        if(map[i] == 0)
        {
            map.erase(std::prev(map.end()));
        }

        int j = std::prev(map.end())->first;
        map[j]--;
        if(map[j] == 0)
        {
            map.erase(std::prev(map.end()));
        }
        int result = (i-1) * (j-1);
        return result;
    }
};
