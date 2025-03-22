#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits.h>

class Span
{
    private :
        unsigned int        _N;
        std::vector<int>    sp;

    public :
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span&   operator=(const Span& other);
        ~Span();

        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
        void    fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        //! Exception
        class addException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        class spanException : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

#endif