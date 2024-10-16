# include <iostream>

// class Student {
//     public:
//         std::string name;
//         int age;
//         Student (std::string name1, int age1){
//             std::cout << "this memory " << this << std::endl;
//             name = name1;
//             age = age1;
//         };
// };

// int main(){
//     Student student1("tiima", 20);

//     std::cout << "obj memory " << &student1 << std::endl;
// }
# include <iomanip>

int main()
{
    std::cout << "hello" << std::setw(18);
    // std::setw(10);
    std::cout << "world" << std::endl;
}