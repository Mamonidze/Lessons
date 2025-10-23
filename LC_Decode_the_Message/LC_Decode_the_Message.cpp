#include <string>
#include <unordered_map>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) {
        std::unordered_map<char, char> map;
        std::string result{};
        char c = 'a';
        for(char ch : key)
        {
            if (ch == ' ') continue;
            if(map.find(ch) == map.end())
            {
                map[ch] = c;
                c++;
            }
        }

        for (auto it : message)
        {
            if (it == ' ')
            {
                result.push_back(' ');
            }
            else
            {
                result.push_back(map[it]);
            }
        }
        return result;
    }
};
