

class MyList
{
    class ListNode
    {
    public:
        // у каждой ноды есть:
        int value;      // значение
        ListNode* prev; // указатель на пред ноду
        ListNode* next; // указатель на след ноду

        ListNode(int v) : value(v), prev(nullptr), next(nullptr){} // конструктор
        ~ListNode(); //деструктор
    };
    //у каждого листа есть:
    ListNode* head{};// указатель на первый элемент
    ListNode* tail{};// указатель на последний элемент
    int size{};    // размер

    MyList(int val, int size): size(size){} //конструктор
    ~MyList(){head = nullptr; tail = nullptr; size = 0;} //деструктор


    void push_back(int &value)
    {
        if(head == nullptr) //если список пустой
        {
            ListNode* newNode = new ListNode(value);
            head = tail = newNode;
            size++;
        }
        else
        {
            ListNode* newNode = new ListNode(value); //создаем новую ноду
            tail->next = newNode; //присоединяем к хвосту
            newNode->prev = tail; // связываем обратно хвост и ноду
            tail = tail->next; // новая нода теперь новый хвост
            size++;
        }
    }

    void push_front(int &value)
    {
        if (head == nullptr) //если список пустой
        {
            push_back(value);
        }
        else
        {
            ListNode* newNode = new ListNode(value); //создаем новую ноду
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            return;
        }
        
        if(head == tail)
        {
            delete head;
            size--;
        }
        else
        {
            tail->prev = tail; //пред элемент теперь новый тейл
            delete tail->next; //удаляем посл элемент
            tail->next = nullptr; //обнуляем некст поинтер
            size--;
        }
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        
        if(head == tail)
        {
            delete head;
            size--;
        }
        else
        {
            
            head->next = head; 
            delete head->prev; 
            head->prev = nullptr; 
            size--;
        }
    }

    void insert(int &value, int pos)
    {
        if (pos >= size)
        {
            return;
        }
        if (head == nullptr || (head == tail && pos == 1))
        {
            push_back(value);
        }
        if ( head == tail && pos == 0)
        {
            push_front(value);
        }
        else
        {
            ListNode* temp = head;
            for (int i = 0; i < pos; ++i)
            {
                temp = temp->next;
            }
            ListNode* newNode = new ListNode(value);
            temp->prev->next = newNode;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->next = temp;
            size++;
        }
    }

    void remove(int &value, int pos)
    {
        if (pos >= size || head == nullptr)
        {
            return;
        }

        if (head == tail || pos == size-1)
        {
            pop_back();
        }
        else if (head == tail || pos == 0)
        {
            pop_front();
        }
        else
        {
            ListNode* temp = head;
            for (int i = 0; i < pos; ++i)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }

    
};



int main()
{
    for (int i = 0; i < MAX; ++i)
    {
        
    }

    return 0;
}
