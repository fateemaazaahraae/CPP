# include "easyfind.hpp"

int main()
{
    std::cout << "#####   Vector Test   #####" << std::endl;
    try
    {
        std::vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        std::cout << easyfind(v, 6) << std::endl;
        std::cout << easyfind(v, 100) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "#####   List Test   #####" << std::endl;
    try
    {
        std::list<int> li;

        li.push_back(10);
        li.push_back(20);
        li.push_back(30);
        li.push_back(40);
        li.push_back(50);

        std::cout << easyfind(li, 50) << std::endl;
        std::cout << easyfind(li, 100) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}