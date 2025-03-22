# include "Span.hpp"

Span::Span() {}

Span::~Span() {}

Span::Span(unsigned int n) : _N(n) 
{
    sp.reserve(_N);
}

Span::Span(const Span& other)
{
    *this = other;
}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        sp = other.sp;
    }
    return *this;
}

void    Span::addNumber(int number)
{
    if (sp.size() < _N)
        sp.push_back(number);
    else
        throw addException();
}

int Span::longestSpan()
{
    int min, max;
    
    if (sp.size() < 2)
        throw spanException();

    min = *std::min_element(sp.begin(), sp.end());
    max = *std::max_element(sp.begin(), sp.end());
    return (max - min);
}

int Span::shortestSpan()
{
    if (sp.size() < 2)
        throw spanException();

    std::vector<int> sortedSp = sp;
    std::sort(sortedSp.begin(), sortedSp.end());

    int minVal = INT_MAX;
    for (std::vector<int>::iterator it = sortedSp.begin(); it != sortedSp.end() - 1; it++) 
    {
        int diff = *(it + 1) - *it;
        if (diff < minVal)
            minVal = diff;
    }
    return minVal;
}

void    Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (sp.size() + std::distance(begin, end) <= _N)
        sp.insert(sp.end(), begin, end);
    else
        throw addException();
}

//! Exception
const char* Span::addException::what() const throw()
{
    return "Cannot add the number : The container is FULL";
}

const char* Span::spanException::what() const throw()
{
    return "The container is EMPTY or contain 1 element";
}