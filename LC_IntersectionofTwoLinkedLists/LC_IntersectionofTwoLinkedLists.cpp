
 struct ListNode {
    int val;
   ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        int size1{};
        int size2{};
        ListNode* l1 {headA};
        ListNode* l2 {headB};

        while (l1)
        {
            l1 = l1->next;
            size1 += 1;
        }

        while (l2)
        {
            l2 = l2->next;
            size2 += 1;
        }
        l1 = headA;
        l2 = headB;

        if (size1 > size2)
        {
            for (int i = 0; i < size1-size2; i++)
            {
                l1 = l1->next;
            }
        }
        
        if (size1 < size2)
        {
            for (int i = 0; i < size2-size1; i++)
            {
                l2 = l2->next;
            }
        }

        while (l1 != l2)
        {
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
};