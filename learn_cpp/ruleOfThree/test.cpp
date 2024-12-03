# include "test.hpp"

test::test() : i(0) {
    std::cout << "default" << std::endl;
}

test::~test() {
    std::cout << "destructor" << std::endl;
}

test::test(const test& other) {
    i = other.i;
    std::cout << "copy" << std::endl;

}

test& test::operator=(const test& other) {
    if (this != &other)
    {
        i = other.i;
    }
    std::cout << "operator" << std::endl;
    return *this;
}

void    test::set(int y)
{
    i = y;
}
int test::get(){
    return (i);
}