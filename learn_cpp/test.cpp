# include <iostream>
# include <string>

int func(int x, int y) {
    std::cout << "here1" << std::endl;
    return (x + y);
}

double func(double x, double y) {
    std::cout << "here2" << std::endl;
    return (x + y);
}

int main()
{
    std::cout << func(5, 4) << std::endl;
    std::cout << func(5, 4) << std::endl;
}