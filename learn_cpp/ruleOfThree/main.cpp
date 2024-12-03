# include "test.hpp"

int main()
{
    test a;
    std::cout << a.get() << std::endl;
    a.set(10);
    std::cout << a.get() << std::endl;
    test b = a;
    std::cout << b.get() << "yyyyyyyyy" << std::endl;
    test c;
    c = b;
}