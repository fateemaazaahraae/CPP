# include "MutantStack.hpp"

int main()
{
    //! INT version
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    //! STRING version
    MutantStack<std::string> mstack2;
    mstack2.push("hello");
    mstack2.push("world");
    mstack2.push("coding");
    MutantStack<std::string>::iterator it1 = mstack2.begin();
    MutantStack<std::string>::iterator ite1 = mstack2.end();
    ++it1;
    --it1;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    return 0;
}