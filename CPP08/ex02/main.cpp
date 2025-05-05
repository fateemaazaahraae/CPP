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
    
    std::cout << "### List test ###" << std::endl;
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Top: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}