#ifndef MODUL2_LAB10_TARRAY_H
#define MODUL2_LAB10_TARRAY_H


#include <iostream>
#include <exception>
#include <initializer_list>

template<
        class T,
        std::size_t N
> struct TArray
{
public:
    using value_type = T;
    using size_type	= size_t;
    using reference	= value_type&;
    using const_reference = const value_type&;
    using pointer = T*;
    using const_pointer	= const T*;
    using iterator = value_type *;
    using const_iterator = const value_type *;
    value_type Ptr[N];

public:
    TArray() = default;
    ~TArray() = default;

    TArray(std::initializer_list<T> init)
            : TArray()
    {
        //memcpy(begin(), init.begin(), size() * sizeof(size_type));        
        int  i = 0;
        for(auto & v : init)
        {
           arr[i] = v;
           i++;
        }                    
    }

    size_type size() const
    {
        return N;
    }

    size_type max_size() const
    {
        return N;
    }

    bool empty() const throw()
    {
        return size() == 0;
    }

    iterator begin() throw()
    {
        return Ptr;
    }

    iterator end() throw()
    {
        return Ptr + N;
    }

    const_iterator cbegin() const throw()
    {
        return Ptr;
    }

    const_iterator cend() const throw()
    {
        return Ptr + N;
    }

    reference at(size_type pos)
    {
        if (pos < 0 || pos >= size())
        {
            throw std::out_of_range("Out of range");
        }

        return Ptr[pos];
    }

    const_reference at( size_type pos ) const
    {
        if (pos < 0 || pos >= size())
        {
            throw std::out_of_range("Out of range");
        }

        return Ptr[pos];
    }

    reference operator[](size_type pos)
    {
        return Ptr[pos];
    }

    const_reference operator[]( size_type pos ) const
    {
        return Ptr[pos];
    }

    reference front()
    {
        return Ptr[0];
    }

    const_reference front() const
    {
        return Ptr[0];
    }

    reference back()
    {
        return Ptr[N - 1];
    }

    const_reference back() const
    {
        return Ptr[N - 1];
    }

    pointer data() throw()
    {
        return Ptr;
    }

    const_pointer data() const throw()
    {
        return Ptr;
    }

    void fill( const reference value )
    {
        for(size_type i = 0; i < size(); ++i)
            Ptr[i] = value;
    }

    void swap( TArray<T,N>& other )
    {
        std::swap(Ptr, other.Ptr);
    }

    friend std::ostream &operator <<(std::ostream &out , TArray const &obj)
    {
        out << "{ ";
        for(int i = 0; i < obj.size(); ++i)
            out << obj.Ptr[i] << " ";
        out << "}";

        return out;
    }
};

#endif //MODUL2_LAB10_TARRAY_H
