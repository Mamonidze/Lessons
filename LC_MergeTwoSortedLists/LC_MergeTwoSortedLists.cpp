
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
        
        ListNode dummy(0); //создаем начальный элемент списка, чтобы было от чего идти
        ListNode* tail = &dummy; //создаем указатель на этот элемент

        while (list1 && list2) //пока оба списка не закончились
        {
            if (list1->val <= list2->val) //если текущее значение из листа1 <= значения из листа 2
            {
                tail->next = list1;//следующее значение в новом списке указывает на меньшее
                list1 = list1->next; //двигаем указатель по списку 1
            }
            else
            {
                tail->next = list2; //следующее значение в новом списке указывает на меньшее
                list2 = list2->next;//двигаем указатель по списку 2
            }
            tail = tail->next; //двигаем хвост в новом списке на 1 элемент вперед
        }

        tail->next = list1 ? list1 : list2; //привязываем последнюю ноду, если 1 список закончился раньше чем второй
        return dummy.next;
    }
};