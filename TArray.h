#ifndef MODUL2_LAB10_TARRAY_H
#define MODUL2_LAB10_TARRAY_H


#include <iostream>
#include <exception>
#include <initializer_list>

template<
        class T,
        std::size_t N
> class TArray
{
public:
    using value_type = T;
    using size_type	= size_t;
    using difference_type = std::ptrdiff_t;
    using reference	= value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer	= const T*;
    using iterator = value_type *;
    using const_iterator = const value_type *;


private:
    value_type * Arr;
public:
    TArray()
    {
        Arr = new T[N];
    }

    TArray(std::initializer_list<T> init)
            : TArray()
    {
        memcpy(begin(), init.begin(), size() * sizeof(size_type));
    }

    size_type size() const
    {
        return N;
    }

    size_type max_size() const
    {
        return std::distance(cbegin(), cend());
    }

    bool empty() const throw()
    {
        return size() == 0;
    }

    iterator begin() throw()
    {
        return Arr;
    }

    iterator end() throw()
    {
        return Arr + N;
    }

    const_iterator cbegin() const throw()
    {
        return Arr;
    }

    const_iterator cend() const throw()
    {
        return Arr + N;
    }

    reference at(size_type pos)
    {
        if (pos < 0 || pos >= size())
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[pos];
    }

    const_reference at( size_type pos ) const
    {
        if (pos < 0 || pos >= size())
        {
            throw std::out_of_range("Out of range");
        }

        return Arr[pos];
    }

    reference operator[](size_type pos)
    {
        return Arr[pos];
    }

    const_reference operator[]( size_type pos ) const
    {
        return Arr[pos];
    }

    reference front()
    {
        return Arr[0];
    }

    const_reference front() const
    {
        return Arr[0];
    }

    reference back()
    {
        return Arr[N - 1];
    }

    const_reference back() const
    {
        return Arr[N - 1];
    }

    pointer data() throw()
    {
        return Arr;
    }

    const_pointer data() const throw()
    {
        return Arr;
    }

    void fill( const reference value )
    {
        for(size_type i = 0; i < size(); ++i)
            Arr[i] = value;
    }

    void swap( TArray<T,N>& other )
    {
        std::swap(Arr, other.Arr);
    }

    friend std::ostream &operator <<(std::ostream &out , TArray const &obj)
    {
        out << "{ ";
        for(int i = 0; i < obj.size(); ++i)
            out << obj.Arr[i] << " ";
        out << "}";

        return out;
    }
};

#endif //MODUL2_LAB10_TARRAY_H
