#include "Span.hpp"

int main()
{
    //! TESTING THE SHORTEST AND LONGEST SPAN
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    //! TESTING THE FILLSPAN MEMBER FUNCTION
    try
    {
        Span sp(10);
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        sp.fillSpan(numbers.begin(), numbers.end());
        std::cout << "Added 5 numbers successfully.\n";

        std::vector<int> moreNumbers;
        moreNumbers.push_back(6);
        moreNumbers.push_back(7);
        moreNumbers.push_back(8);
        moreNumbers.push_back(9);
        moreNumbers.push_back(10);
        moreNumbers.push_back(11);

        sp.fillSpan(moreNumbers.begin(), moreNumbers.end());
        std::cout << "Added more numbers successfully (this should not print).\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
