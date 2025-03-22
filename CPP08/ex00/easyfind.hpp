# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

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
    // I should search for the purpose of adding the "template" keyword before the variable
    typename T::iterator it;
    it = std::find(arr.begin(), arr.end(), n);
    if (it != arr.end())
        return (it - arr.begin());
    throw IndexException();
}

#endif