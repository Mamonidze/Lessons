#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {

        std::map<int, int> map{};

        for(int i : nums)
        {
            map[i]++;
        }

        std::vector<int>arr{};

        while (!map.empty()) {

            int a = map.begin()->first;
            map[a]--;
            if(map[a] == 0)
            {
                map.erase(map.begin());
            }
            
            int b = map.begin()->first;
            map[b]--;
            if(map[b] == 0)
            {
                map.erase(map.begin());
            }
            arr.push_back(b);
            arr.push_back(a);
        }
        return arr;
    }
};
