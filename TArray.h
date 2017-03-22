#ifndef MODUL2_LAB10_TARRAY_H
#define MODUL2_LAB10_TARRAY_H

#include <iostream>
#include <exception>

template<typename T>
class TArray
{
public:
    using value_type = T;
    using size_type = size_t;
    using iterator = value_type *;
    using reference = value_type&;
    using const_reference = const value_type&;


private:
    size_type Count;
    size_type Capacity;
    value_type * Arr;
public:
    TArray()
            : Arr(nullptr)
            , Count(0)
            , Capacity(0)
    { }

    TArray(size_type capacity)// +
            : Count(0)
            , Capacity(capacity)
    {
        Arr = new value_type[Capacity];
    }

    ~TArray()// +
    {
        delete[] Arr;
    }

    void push_back(T elem)// +
    {
        if(Count >= Capacity)
            throw std::out_of_range("Out of range");

        Arr[Count] = elem;
        Count++;
    }

    TArray(const TArray &rhs)// +
    {
        Capacity = rhs.Capacity;
        Arr = new value_type[Capacity];
        memcpy(Arr, rhs.Arr, rhs.Count * sizeof(size_type));
    }

    TArray &operator = (const TArray &rhs)// +
    {
        if (this == &rhs)
            return *this;

        memcpy(Arr, rhs.Arr, rhs.Count * sizeof(size_type));
        Count = rhs.Count;

        return *this;
    }

    iterator begin() const throw()
    {
        return Arr;
    }

    iterator end() const throw()
    {
        return Arr + Count;
    }

    reference at(size_type index)
    {
        if (index < 0 || index >= Count)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[index];
    }

    value_type at(size_type index) const
    {
        if (index < 0 || index >= Count)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[index];
    }

    reference operator[](size_type index)
    {
        return Arr[index];
    }

    const_reference operator[](size_type index) const
    {
        return Arr[index];
    }

    reference front()
    {
        if (Arr == nullptr)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[0];
    }

    const_reference front() const
    {
        if (Arr == nullptr)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[0];
    }

    reference back()
    {
        if (Arr == nullptr)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[Count - 1];
    }

    const_reference back() const
    {
        if (Arr == nullptr)
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[Count - 1];
    }

    void swap(TArray& other) throw()
    {
        std::swap(Arr, other.Arr);
        std::swap(Count, other.Count);
        std::swap(Capacity, other.Capacity);
    }

    bool Empty()// +
    {
        return size() == 0;
    }

    size_type size() const// +
    {
        return Count;
    }

    size_type capacity() const// +
    {
        return Capacity;
    }

    void fill(int index, size_type value)
    {
        Arr[index] = value;
    }

    value_type get(int index) const
    {
        return Arr[index];
    }

    friend std::ostream &operator <<(std::ostream &out , TArray const &obj)
    {
        out << "{ ";
        for(int i = 0; i < obj.Capacity; ++i)
            out << obj.Arr[i] << " ";
        out << "}";

        return out;
    }
};

#endif //MODUL2_LAB10_TARRAY_H
