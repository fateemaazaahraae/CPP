#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    func(T element)
{
    std::cout << element << std::endl;
}

template <typename T, typename F>
void    iter(T* add, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(add[i]);
}


#endif