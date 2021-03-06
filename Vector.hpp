#ifndef __VECTOR_HPP
#define __VECTOR_HPP
#include <cstddef>
#include <cassert>

/// template class vector representing container of objects
template <typename T>
class Vector
{
protected:
    /// default capacity on create
    static const unsigned INIT_CAPACITY = 2;
    /// array of objects
    T *data;
    /// size and capacity of the container
    size_t m_size, m_capacity;
    /// double the capacity of the vector
    void expand();
    /// reduce the capacity of the vector by 2
    void shrink();
    /// copy data from another vector
    void copy(const Vector &other);

public:
    /// construct vector with certain capacity
    Vector(size_t cap = INIT_CAPACITY) : data(new T[cap]), m_capacity(cap), m_size(0) {}
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
    ~Vector();

    unsigned getCount() const { return m_size; }
    /// add new object to the end of this container
    Vector &push_back(const T &el);
    Vector &remove(const T &el);
    /// remove last object from the container (returned as result)
    T pop_back();
    /// remove object at particular index from the container (returned as result)
    T pop_at(unsigned index);
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return !m_size; }
    const T &operator[](unsigned index) const;
};

template <typename T>
void Vector<T>::expand()
{
    m_capacity <<= 1;
    T *newData = new T[m_capacity];
    for (unsigned i = 0; i < m_size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::shrink()
{
    m_capacity >>= 1;
    T *newData = new T[m_capacity];
    for (unsigned i = 0; i < m_size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

template <typename T>
void Vector<T>::copy(const Vector &other)
{
    delete[] data;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    data = new T[m_capacity];
    for (unsigned i = 0; i < m_size; ++i)
        data[i] = other.data[i];
}

template <typename T>
Vector<T>::Vector(const Vector &other)
    : data(nullptr), m_size(0)
{
    copy(other);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
Vector<T> &Vector<T>::push_back(const T &el)
{
    if (m_size == m_capacity)
        expand();
    data[m_size++] = el;
    return *this;
}

template <typename T>
T Vector<T>::pop_back()
{
    assert(m_size);
    return data[--m_size];
}

template <typename T>
Vector<T> &Vector<T>::remove(const T &el)
{
    unsigned i = 0;
    while (i < m_size && data[i] != el)
        ++i;
    if (i < m_size)
    {
        --m_size;
        while (i < m_size)
        {
            data[i] = data[i + 1];
            ++i;
        }
    }
    return *this;
}

template <typename T>
T Vector<T>::pop_at(unsigned index)
{
    assert(index < m_size);
    T el = data[index];
    --m_size;
    while (index < m_size)
    {
        data[index] = data[index + 1];
        ++index;
    }
    return el;
}

template <typename T>
const T &Vector<T>::operator[](unsigned index) const
{
    assert(index < m_size);
    return data[index];
}

#endif