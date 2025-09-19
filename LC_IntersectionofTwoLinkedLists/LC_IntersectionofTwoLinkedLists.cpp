
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //если хотя бы 1 из списков пуст - возвращаем nullptr
        if(!headA || !headB) return nullptr;

        //создаем 2 указателя, которые будут бежать по спискам
        ListNode* pA = headA; 
        ListNode* pB = headB;

        while (pA != pB) //бежим пока у указателей не совпадут адреса. Если совпадающих нет - совпадут на nullptr
        {
            //т.к. листы могут быть разной длины, каждым указателем бежим по обоим. Если 1 заканчивается - перепрыгиваем на другой
            if (pA == nullptr)
            {
                pA = headB;
            }
            else
            {
                pA = pA->next; //если pA != nullptr - двигаем pA
            }

            if (pB == nullptr)
            {
                pB = headA;
            }
            else
            {
                pB = pB->next; //если pB != nullptr - двигаем pB
            }
        }
        return pA;

    }
};


int main(int argc, char* argv[])
{
    
    return 0;
}
