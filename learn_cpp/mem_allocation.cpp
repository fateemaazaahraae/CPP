# include <iostream>

// int main()
// {
//     int *ptrNum = NULL;

//     ptrNum = new int;

//     *ptrNum = 33;

//     std::cout << *ptrNum << std::endl;
//     std::cout << ptrNum << std::endl;
//     delete(ptrNum);
//     std::cout << *ptrNum << std::endl; // its gone
//     std::cout << ptrNum << std::endl;

// }

// int main()
// {
//     char *pNames;
//     int size;
//     int i;

//     std::cout << "How many students do you have ??" << std::endl;
//     std::cin >> size;
//     pNames = new char[size];
//     i = 0;
//     while (i < size)
//     {
//         std::cout << "Enter the name of #" << i + 1<< ": ";
//         std::cin >> pNames[i];
//         std::cout << std::endl;
//         i++;
//     }
//     i = 0;
//     while (i < size)
//     {
//         std::cout << pNames[i] << "  ";
//         i++;
//     }
//     delete[] pNames;
// }


class student {
    private:
        std::string name;
    public:
        void present(std::string h)
        {
            name = h;
            std::cout << name << " is present\n";
        }
};

int main()
{
    student* ali = new student;
    ali->present("ali");
}