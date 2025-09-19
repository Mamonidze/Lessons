struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;                       //создаем темповый указатель
        while(current && current->next)                 //пока текущий элемент и след != nullptr
        {
            if (current->val == current->next->val)     //если значение текущего = значению след ->дубликат
            {
                current->next = current->next->next;    //меняем указатель след на элемент после него (через 1)
            }
            else                                        //если значение текущего != значению след -> разные
            {
                current = current->next;                //двигаем текущий указатель на указатель следующего      
            }
        }
        return head;
    }
};