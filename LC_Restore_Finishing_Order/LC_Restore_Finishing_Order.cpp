#include <unordered_set>

class Solution {
public:
    std::vector<int> recoverOrder(std::vector<int>& order, std::vector<int>& friends) {
        std::vector<int> result;
        std::unordered_set<int> friends_set;
        for(auto i : friends)
        {
            friends_set.emplace(i);
        }

        for (int i = 0; i < order.size(); ++i)
        {
            if(friends_set.find(order[i]) != friends_set.end())
            {
                result.push_back(order[i]);
            }
        }

        return result;

    }
};
