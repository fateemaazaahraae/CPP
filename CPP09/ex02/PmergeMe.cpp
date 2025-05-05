# include "PmergeMe.hpp"

const char* PmergeMe::InvalidInputException::what() const throw()
{
    return "Error: Invalid Input";
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe&   PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

PmergeMe::PmergeMe(std::vector<int> vec)
{
    vecStruggle = -1;
    deqStruggle = -1;
    fillVector(vec);
    fillDeque(vec);
}

PmergeMe::~PmergeMe() {}

//! VECTOR FUNCTIONS
void    PmergeMe::fillVector(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        myVector.push_back(vec[i]);
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    return a.first < b.first;
}

std::vector<std::pair<int, int> >   PmergeMe::pairAndSortElementVec(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > pairs;

    if (vec.size() % 2 != 0)
        vecStruggle = vec.back();

    //? Make Pairs
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
        pairs.push_back(std::make_pair(vec[i], vec[i + 1]));

    //? Sort Pairs
    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    //? Sort The Pairs Itself
    std::sort(pairs.begin(), pairs.end(), comparePairs);
    return pairs;
}

//! END VECTOR


//! DEQUE FUNCTIONS
void    PmergeMe::fillDeque(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        myDeque.push_back(vec[i]);
}

//! END DEQUE

void    PmergeMe::displayFirstLine()
{
    std::cout << "Before:  ";
    for (size_t i = 0; i < myVector.size(); i++)
    {
        std::cout << myVector[i];
        if (i != myVector.size() - 1)
            std::cout << " ";
    }
}



void    PmergeMe::mergeInsertionSort()
{
    std::vector<std::pair<int, int> > pairs;
    displayFirstLine();

    //! VECTOR part
    pairs = pairAndSortElementVec(myVector);
    // displaySecondLine();

    //! DEQUE part
    // displayThirdLine();
    // displayLastLine();
}


//! Helper functions
void    checkDigit(std::string& str)
{
    int i = 0;
    
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '\0')
        throw PmergeMe::InvalidInputException();
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            throw PmergeMe::InvalidInputException();
        i++;
    }
}

std::vector<int>   convertStringVec(std::vector<std::string>& stringVec)
{
    std::vector<int> intVec;
    long num;

    for (size_t i = 0; i < stringVec.size(); i++)
    {
        num = atol(stringVec[i].c_str());
        if (num > INT_MAX || num < INT_MIN)
            throw PmergeMe::InvalidInputException();
        intVec.push_back(static_cast<int> (num));
    }
    return intVec;
}

std::vector<int>   parseInput(std::vector<std::string>& vec)
{
    std::vector<int> intVec;

    for (size_t i = 0; i < vec.size(); i++)
        checkDigit(vec[i]);
    return convertStringVec(vec);
}