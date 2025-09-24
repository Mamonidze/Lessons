

#include <valarray>

 struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int size{};
        ListNode* it{head};
        while (it)
        {
            size++;
            it = it->next;
        }
        it = head;
        int power = size-1;
        int sum{};

        for(int i = 0; i < size; i++)
        {
            sum += it->val * (pow(2, power));
            power--;
            it = it->next;
        }
        return sum;
    }
};