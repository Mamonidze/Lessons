
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head->next == nullptr)
        {
            return nullptr;
        }
        
        int size{};
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            size++;
        }
        temp = head;

        if(n == size)
        {
            head = head->next;
        }
        else if (n!=size)
        {
            for (int i = 1; i < size-n; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};