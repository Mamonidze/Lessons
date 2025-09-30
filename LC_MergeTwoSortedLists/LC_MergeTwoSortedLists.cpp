
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1{list1};
        ListNode* l2{list2};
        ListNode* l3 = nullptr;          
        for (int i = 0; i < 5; ++i)
        {
           
        }


              if (list2 == nullptr)
        {
            return list1;
        }

        if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }

        if (l1->val <= l2->val)
        {
            l3 = l1;
            l1 = l1->next;
        }
        else
        {
            l3 = l2;
            l2 = l2->next;
        }

        ListNode* l4 = l3;
        while(l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }

        l3->next = l1 ? l1 : l2;
        return l4;
        
        
    }
};