#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    double minimumAverage(std::vector<int>& nums) {
        std::map<int, int> map;
        for (int i : nums)
            map[i]++;

        std::vector<double> averages;

        for (int i = 0; i < nums.size()/2; i++) {
            auto itMin = map.begin();
            int minElement = itMin->first;

            itMin->second--;
            if (itMin->second == 0)
                map.erase(itMin);

            auto itMax = --map.end();  
            int maxElement = itMax->first;

            itMax->second--;
            if (itMax->second == 0)
                map.erase(itMax);

            averages.push_back((minElement + maxElement) / 2.0);
        }
        double ans = averages[0];
        for (double i : averages)
            ans = std::min(ans, i);

        return ans;
    }
};
