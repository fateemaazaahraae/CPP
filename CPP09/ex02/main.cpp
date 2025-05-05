# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<std::string> vec;
    int i;

    try
    {
        if (ac > 1)
        {
            i = 1;
            for (; av[i]; i++)
                vec.push_back(av[i]);
            PmergeMe obj(parseInput(vec));
            obj.mergeInsertionSort();
        }
        else
            throw PmergeMe::InvalidInputException();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}