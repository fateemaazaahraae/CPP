# include "Serializer.hpp"

int main()
{
    Data    *ptr1;
    Data    *ptr2;

    ptr1 = new Data;
    ptr1->c = 'z';
    ptr1->x = 100;

    std::cout << ptr1 << ": " << "c: " << ptr1->c << " x: " << ptr1->x << std::endl;

    uintptr_t a = Serializer::serialize(ptr1);
    std::cout << "The uintptr_t a : " << a << std::endl;
    std::cout << ptr1 << ": " << "c: " << ptr1->c << " x: " << ptr1->x << std::endl;
    ptr2 = Serializer::deserialize(a);
    std::cout << ptr2 << ": " << "c: " << ptr2->c << " x: " << ptr2->x << std::endl;
    delete ptr1;
}