# include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        std::cout << easyfind(v, 30) << std::endl;
        std::cout << easyfind(v, 100) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}