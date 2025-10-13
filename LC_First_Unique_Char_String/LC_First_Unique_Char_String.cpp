#include <string>
#include <unordered_map>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map{};
        for(auto i : s)
        {
            map[i]++; //увеличиваем счетчик на каждом соотв ключе, т.е букве
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(map[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
