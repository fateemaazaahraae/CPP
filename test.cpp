#include <iostream>

void swap(int& a, int& b) {  // Global swap function
    int temp = a;
    a = b;
    b = temp;
}

class Example {
public:
    void swap(int& a, int& b) {  // Member function swap
        std::cout << "Class swap called!\n";
    }
};

int main() {
    int x = 1, y = 2;
    Example ex;

    ex.swap(x, y);  // Calls the member function inside Example
    swap(x, y);     // Calls the global function
    ::swap(x, y);   // Forces use of the global function

    return 0;
}
