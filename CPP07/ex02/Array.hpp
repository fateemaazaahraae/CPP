#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
    private :
        unsigned int    _n;
        T*              array;

    public :
        //! O.C.F
        Array() : _n(0) { array = new T[_n]; }

        Array(unsigned int n) : _n(n) { array = new T[_n]; }

        Array(const Array& other)
        {
            _n = other._n;
            array = new T[_n];
            for (size_t i = 0; i < _n; i++)
                array[i] = other.array[i];
        }

        Array&  operator=(const Array& other)
        {
            _n = other._n;
            if (this != &other)
            {
                delete[] array;
                array = new T[_n];
                for (size_t i = 0; i < _n; i++)
                    array[i] = other.array[i];
            }
            return *this;
        }

        ~Array() { delete[]  array; }

        //! Exception
        class IndexException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("Index out of bounds !");
                }
        };

        T&  operator[](unsigned int index)
        {
            if (index < 0 || index >= _n)
                throw IndexException();
            return array[index];
        }

        const T&  operator[](unsigned int index) const
        {
            if (index < 0 || index >= _n)
                throw IndexException();
            return array[index];
        }

        unsigned int size() const { return _n; }
};

#endif