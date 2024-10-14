# include <iostream>
# include "MyClass.hpp"

MyClass::MyClass (int num, std::string ptr) : var(num), str(ptr){};

MyClass::~MyClass (void) {
    std::cout << var << std::endl;
    std::cout << str << std::endl;

}

int main() {
    MyClass obj(1337, "ali");
    std::cout << "here is\n";
}