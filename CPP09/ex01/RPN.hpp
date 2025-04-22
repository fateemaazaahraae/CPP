#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN 
{
    private :
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN&    operator=(const RPN& other);

    public :
        class argException : public std::exception
        {
            const char* what() const throw();
        };

        class badArgumentException : public std::exception
        {
            const char* what() const throw();
        };

        class devZeroException : public std::exception
        {
            const char* what() const throw();
        };

        static void reversePolishNotation(std::stack<int>& stack, std::string input);
        static bool isNumber(std::string input);
        static bool isOperator(std::string input);
};

#endif