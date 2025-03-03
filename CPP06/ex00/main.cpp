# include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Enter One Argument." << std::endl;
        return 1;
    }
    (void)av;
    ScalarConverter::convert(av[1]);
}