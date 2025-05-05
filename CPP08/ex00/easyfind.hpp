# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <list>

class IndexException : public std::exception
{
    public :
        const char* what() const throw() 
        {
            return "No occurrence is found !";
        }
};

template <typename T>
int    easyfind(T& arr, int n)
{
    typename T::iterator it;
    it = std::find(arr.begin(), arr.end(), n);
    if (it != arr.end())
        return std::distance(arr.begin(), it);
    throw IndexException();
}

#endif