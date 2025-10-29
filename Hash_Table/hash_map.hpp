
template<typename T>
hash_map<T>::hash_map() : size(0)
{
    set.reserve(default_size);
}

template<typename T>
hash_map<T>::hash_map(size_t size):size(size)
{
    set.resize(size);
}

template<typename T>
hash_map<T>::hash_map(const hash_map& other)
{
    this->size = other.size;
    this->set  = other.set;
}

template<typename T>
hash_map<T>& hash_map<T>::operator=(const hash_map& other)
{
    if (this == &other)
    {
        return *this; //self-assignment
    }
    this->size = other.size;
    this->set = other.set;
    return *this;
}

template<typename T>
bool hash_map<T>::insert(const T& value)
{
    std::hash<T> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    std::list<T>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) //если такое значение есть - фолс
        {
            return false;
        }
    }
    
    l.push_back(value); //если значения нет - пушбек в лист, size++ , тру
    size++;
    return true;
}

template<typename T>
bool hash_map<T>::find(const T& value) const 
{
    std::hash<T> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    const std::list<T>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) 
        {
            return true;
        }
    }
    return false;
}

template<typename T>
bool hash_map<T>::erase(const T& value)
{
    std::hash<T> int_hash; 
    size_t index = int_hash(value); //хешируем валью, чтобы узнать индекс
    if (index > this->set.size()) //если индекс больше сайза вектора - index&size (т.е. остаток)
    {
        index = index % this->set.size();
    }
    std::list<T>& l = this->set[index];
    for (auto it = l.begin(); it != l.end(); ++it) //бежим по списку, который лежит под текущим индексом
    {
        if (*it == value) 
        {
            set[index].erase(it);
            return true;
        }
    }
    return false;
}








