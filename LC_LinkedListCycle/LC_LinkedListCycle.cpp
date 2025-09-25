
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;  // пустой или 1 элемент → цикла нет

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // 🐢 двигается на 1
            fast = fast->next->next;     // 🐇 двигается на 2

            if (slow == fast) return true;  // встретились → цикл найден
        }

        return false;  // дошли до конца → цикла нет
    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
