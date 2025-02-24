# include <iostream>
# include <exception>


// void fun1()
// {
//     std::cout << "helloeeeeeeeeeeeeee\n";
//         throw -1;
// }

// void    fun()
// {
//     std::cout << "hello\n";
//     fun1();
// }

// class test : public std::exception {
//     public :
//         virtual const char* what() { return "Failed: this is a user-defined exception"; }

// };

class base {
    public:
        base(){}
};

class derived : public base{
    public:
        derived(){}
};

int main()
{
    try{
        throw derived();
    }
    catch (const base& b)
    {
        std::cout << "Caught base" << std::endl;
    }
    catch (const derived& d)
    {
        std::cout << "Caught derived" << std::endl;
    }
}
