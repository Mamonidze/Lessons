
template<typename T>
void List<T>::push_back(const T &value)
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

template<typename T>
void List<T>::push_front(const T &value)
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

template<typename T>
void List<T>::pop_back()
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

template<typename T>
void List<T>::pop_front()
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

template<typename T>
void List<T>::insert(T &value, size_t pos)
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

template<typename T>
void List<T>::erase(size_t pos)
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