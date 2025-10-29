#pragma once

template<typename T>
Vector<T>::Vector ()
{
    data = nullptr;
    size = 0;
    capacity = 0;
    std::cout << "Default constructor" << '\n'; //DEBUG
}

template<typename T>
Vector<T>::Vector(const size_t n) : size(n), capacity(n)
{
    data = new T[n]; //create new empty vector
    std::cout << "Size Constructor" << '\n'; //DEBUG
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Vector index out of range");
    }
    return data[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Vector index out of range");
    }
    return data[index];
}

template<typename T>
void Vector<T>::push_back(const T& x)
{
    if (size == capacity)
    {
        constexpr int multiplier{2};
        const size_t new_capacity = capacity * multiplier; // new capacity
        T* new_data = new T[new_capacity]; //new array for copying old array + 1

        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i]; //copying from old arr to new arr
        }
        delete[] data; //delete old arr
        data = new_data; // change pointer from old to new
        capacity = new_capacity; // change old capacity to new
    }
    data[size] = x; //add new element at the end of   
    size++; // increase size
}

template<typename T>
void Vector<T>::pop_back()
{
    if (size != 0)
    {
        data[size-1].~T();
        size--;
    }
}

template<typename T>
void Vector<T>::insert(size_t position, const T& element)
{
    if (position > size)
    {
        throw std::out_of_range("Position is out of vector range");
    }

    if (size == capacity)
    {
        constexpr int multiplier{2};
        capacity *= multiplier;
        T* new_data = new T[capacity]; // create new array for copying
        for (size_t i = 0; i < size; i++)
        {
            new_data[i] = data[i]; // copying from old arr to new arr
        }
        delete[] data; // delete old_arr
        data = new_data; // change pointer from old arr to new
    }
    for (size_t i = size; i > position; --i)
    {
        data[i] = data[i-1];
    }
    data[position] = element;
    size++;

}

template<typename T>
void Vector<T>::erase(size_t position)
{
    if (position >= size)
    {
        throw std::out_of_range("Position is out of vector range");
    }
    for (size_t i = position; i < size-1; i++)
    {
        data[i] = data[i+1];
    }
    size--;

}

template<typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        os << vec.data[i] << ' ';
    }
    return os;
}





