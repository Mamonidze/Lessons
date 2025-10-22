#include <string>
#include <unordered_set>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        int counter{0};
        std::unordered_set<char> set_allowed(allowed.begin(), allowed.end());

        for(auto word : words)
        {
            bool IsConsistent{true};
            for(auto ch : word)
            {
                if(set_allowed.find(ch) == set_allowed.end())
                {
                    IsConsistent = false;
                    break;
                }
            }
            if (IsConsistent)
            {
                counter++;
            }
        }
        return counter;
    }
};
