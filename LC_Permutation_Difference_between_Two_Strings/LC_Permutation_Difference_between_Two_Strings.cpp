#include <map>
#include <string>

class Solution {
public:
    int findPermutationDifference(std::string s, std::string t) {
        std::map <char, int> mapS{};
        std::map<char, int> mapT{};
        int sum{0};

        for(int i = 0; i < s.size(); ++i)
        {
            mapS[s[i]] = i;
        }
        
        for(int i = 0; i < t.size(); ++i)
        {
            mapT[t[i]] = i;
        }

        for (char ch : s)
        {
            sum += std::abs(mapS[ch] - mapT[ch]);
        }
            

        return sum;
    }
};
