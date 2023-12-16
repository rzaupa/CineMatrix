#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>

template <class T>
bool defaultEqual(const T &a, const T &b)
{
    return a == b;
}

template <class T>
class mySet
{
private:
    using equalFuncPtr = bool (*)(const T &, const T &);
    T *array;
    unsigned int size;
    unsigned int capacity;
    T *copy() const;
    equalFuncPtr myEqualFunc;

public:
    mySet();
    mySet(equalFuncPtr);
    mySet(const mySet &v);
    ~mySet();
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    bool push_back(const T &element);
    const T remove(const T &element);
    bool contains(const T &);
    void clear();
    int &operator[](unsigned int i) const;
    mySet &operator=(const mySet &);
    class iterator
    {
    private:
        T *ptr;

    public:
        iterator(T *ptr);
        T &operator*() const;
        T *operator->() const;
        iterator &operator++();
        iterator operator++(int);
        iterator operator+(int);
        bool operator==(const iterator &it) const;
        bool operator!=(const iterator &it) const;
    };
    iterator begin() const;
    iterator end() const;
    iterator find(const T &element) const;
};

#endif

template <class T>
T *mySet<T>::copy() const
{
    if (size == 0)
        return nullptr;
    T *copy = new T[size];
    for (unsigned int i = 0; i < size; i++)
        copy[i] = array[i];
    return copy;
}

template <class T>
mySet<T>::mySet() : array(nullptr), size(0), capacity(0), myEqualFunc(defaultEqual) {}

template <class T>
mySet<T>::mySet(const mySet<T> &v) : array(v.copy()), size(v.size), myEqualFunc(v.myEqualFunc) {}

template <class T>
mySet<T>::mySet(equalFuncPtr eqf) : array(nullptr), size(0), capacity(0), myEqualFunc(eqf) {}

template <class T>
mySet<T>::~mySet()
{
    clear();
}

template <class T>
unsigned int mySet<T>::getSize() const
{
    return size;
}
template <class T>
unsigned int mySet<T>::getCapacity() const
{
    return capacity;
}

template <class T>
bool mySet<T>::contains(const T &target)
{
    return find(target) != end();
}

template <class T>
bool mySet<T>::push_back(const T &element)
{
    if (size == capacity)
    {
        unsigned int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T *tempArray = new T[newCapacity];
        for (unsigned int i = 0; i < size; i++)
        {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        capacity = newCapacity;
    }
    if (contains(element))
    {
        return false;
    }
    array[size] = element;
    size++;
    return true;
}

template <class T>
const T mySet<T>::remove(const T &element)
{
    auto it = find(element);
    const T ret = *it;
    if (it != end())
    {
        for (; it != end(); it++)
        {
            *it = *(it + 1);
        }
        size--;
    }
    return ret;
}

template <class T>
void mySet<T>::clear()
{
    if (array != nullptr)
        delete[] array;
}

template <class T>
int &mySet<T>::operator[](unsigned int i) const
{
    if (i >= size)
    {
        throw std::out_of_range("Index out of range");
    }
    return array[i];
}

template <class T>
mySet<T> &mySet<T>::operator=(const mySet<T> &v)
{
    if (this != &v)
    {
        delete[] array;
        array = v.copy();
        size = v.size;
    }
    return *this;
}

template <class T>
mySet<T>::iterator::iterator(T *ptr) : ptr(ptr) {}

template <class T>
T &mySet<T>::iterator::operator*() const
{
    return *ptr;
}

template <class T>
T *mySet<T>::iterator::operator->() const
{
    return ptr;
}

template <class T>
typename mySet<T>::iterator &mySet<T>::iterator::operator++()
{
    ptr++;
    return *this;
}

template <class T>
typename mySet<T>::iterator mySet<T>::iterator::operator+(int i)
{
    return ptr + i;
}

template <class T>
typename mySet<T>::iterator mySet<T>::iterator::operator++(int)
{
    iterator temp = *this;
    ++(*this);
    return temp;
}

template <class T>
bool mySet<T>::iterator::operator==(const iterator &it) const
{
    return ptr == it.ptr;
}

template <class T>
bool mySet<T>::iterator::operator!=(const iterator &it) const
{
    return ptr != it.ptr;
}

template <class T>
typename mySet<T>::iterator mySet<T>::begin() const
{
    return iterator(array);
}

template <class T>
typename mySet<T>::iterator mySet<T>::end() const
{
    return iterator(array + size);
}

template <class T>
typename mySet<T>::iterator mySet<T>::find(const T &element) const
{
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        if (myEqualFunc(*it, element))
        {
            return it;
        }
    }
    return end();
}