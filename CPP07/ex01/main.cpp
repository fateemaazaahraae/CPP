# include "Iter.hpp"

int main()
{
    std::cout << "##### TEST1 #####\n";

    int arrInt[] = {0, 1, 2, 3, 4};
    iter(arrInt, 5, func<int>);

    std::cout << "##### TEST2 #####\n";

    char arrChar[] = {'a', 'b', 'c', 'd'};
    iter(arrChar, 4, func<char>);
}