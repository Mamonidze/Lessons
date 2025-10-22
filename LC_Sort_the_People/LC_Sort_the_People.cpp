#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        std::map<int, std::string> map {};
        std::vector<std::string> v{};

        for (size_t i = 0; i < heights.size(); ++i) {
            map[heights[i]] = names[i];
        }

        for (auto it = map.rbegin(); it != map.rend(); ++it) {
            v.push_back(it->second);
        }

        return v;
    }
};
