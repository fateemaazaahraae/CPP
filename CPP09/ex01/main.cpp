# include "RPN.hpp"

int main(int ac, char **av)
{
    std::stack<int> stack;
    std::string input;

    try
    {
        if (ac == 2)
        {
            std::istringstream s(av[1]);
            while (s >> input)
                RPN::reversePolishNotation(stack, input);
            if (!stack.empty() && stack.size() == 1)
                std::cout << stack.top() << std::endl;
        }
        else
            throw RPN::argException();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}