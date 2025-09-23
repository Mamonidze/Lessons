#include <unordered_map>

class ListNode
{
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value, ListNode *next, ListNode *prev) : val(value), next(next), prev(prev) {}
};

class MyList
{
private:
    ListNode* head; // голова списка
    ListNode* tail; // хвост списка
    int size;       // размер списка

public:
    MyList() : head(NULL), tail(NULL), size(0) {} // базовый конструктор

    void push_back(const int &value) //функция пуш бека
    {
        ListNode* newNode = new ListNode(value, nullptr, tail); //создаем новую ноду в конце списка: value - значение, next - null потому что посл эл показывает в нуль, prev - tail, потому что новый элт должен указывать на конец списка
        if (tail)                                                       // если tail != nullptr (то есть список не является пустым)
        {
            tail->next = newNode;                                       //указатель на след элемент у хвоста должен указывать на новую ноду
        }
        else                                                            //если список пуст, то есть tail == nullptr
        {
            head = newNode;                                             //голова тоже должна указывать на новую ноду, т.к она единственная в списке
        }
        tail = newNode;                                                 //теперь новая нода - новый хвост списка
        size++;                                                         //увеличиваем размер
    }

    void push_front(const int &value)
    {
        ListNode* newNode = new ListNode(value, head, nullptr);
        if (head)
        {
            head->prev= newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
        size++;
    }

    void insert(const int &value, const int &pos)
    {
        ListNode* newNode = new ListNode(value, nullptr, nullptr);
        if (pos == 1)
        {
            this->push_front(value);
        }
        if (pos >= size)
        {
            this->push_back(value);
        }

        ListNode* temp = head->next;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        size++;
        
    }

    MyList& operator=(const MyList& other)
    {
        if (this == &other)
        {
            return *this; //self-assignment
        }
        this->head = other.head;
        this->tail = other.tail;
        this->size = other.size;
        for (int i = 0; i < other.size; i++)
        {
            
        }
        return *this;
    }
    
};



int main()
{
    MyList mainlist;
    mainlist.push_back(4);
    mainlist.push_front(5);
    
    return 0;
}
