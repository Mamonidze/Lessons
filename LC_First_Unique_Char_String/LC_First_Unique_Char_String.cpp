#include <xstring>

class Solution {
public:
    int firstUniqChar(std::string s) {

        for (int i = 0; i < s.length(); i++)
        {
            bool IsUnique = true;

            for (int j = 0; j < s.length(); j++)
            {
                if(i != j && s[i] == s[j])
                {
                    IsUnique = false;
                    break;
                }
            }
            if (IsUnique)
            {
                return i;
            }
        }
    
        return -1;
    }
};
