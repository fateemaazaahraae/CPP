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
    {
        vecStruggle = vec.back();
        vec.pop_back();
    }

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

std::vector<int>    PmergeMe::extractFirstEleVec(std::vector<std::pair<int, int> > pairs)
{
    std::vector<int> sortedVec;

    //? Extract first
    for (size_t i = 0; i < pairs.size(); i++)
        sortedVec.push_back(pairs[i].first);

    //? Insert second
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int value = pairs[i].second;
        std::vector<int>::iterator pos = std::lower_bound(sortedVec.begin(), sortedVec.end(), value);
        sortedVec.insert(pos, value);
    }

    //? Insert the struggle if exist
    if (vecStruggle != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedVec.begin(), sortedVec.end(), vecStruggle);
        sortedVec.insert(pos, vecStruggle);
    }
    return sortedVec;
}

//! END VECTOR


//! DEQUE FUNCTIONS
void    PmergeMe::fillDeque(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        myDeque.push_back(vec[i]);
}

std::deque<std::pair<int, int> >   PmergeMe::pairAndSortElementDeq(std::deque<int> deq)
{
    std::deque<std::pair<int, int> > pairs;

    if (deq.size() % 2 != 0) 
    {
        deqStruggle = deq.back();
        deq.pop_back();
    }

    //? Make Pairs
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));

    //? Sort Pairs
    for (size_t i = 0; i < pairs.size(); i++)
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);

    //? Sort The Pairs Itself
    std::sort(pairs.begin(), pairs.end(), comparePairs);
    return pairs;
}

std::deque<int>     PmergeMe::extractFirstEleDeq(std::deque<std::pair<int, int> > pairs)
{
    std::deque<int> sortedDeq;

    //? Extract first
    for (size_t i = 0; i < pairs.size(); i++)
        sortedDeq.push_back(pairs[i].first);

    //? Insert second
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int value = pairs[i].second;
        std::deque<int>::iterator pos = std::lower_bound(sortedDeq.begin(), sortedDeq.end(), value);
        sortedDeq.insert(pos, value);
    }

    //? Insert the struggle if exist
    if (deqStruggle != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(sortedDeq.begin(), sortedDeq.end(), deqStruggle);
        sortedDeq.insert(pos, deqStruggle);
    }
    return sortedDeq;
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

void    PmergeMe::displaySecondLine(std::vector<int>& sortedVec)
{
    std::cout << "\nAfter:  ";
    for (size_t i = 0; i < sortedVec.size(); i++)
    {
        std::cout << sortedVec[i];
        if (i != sortedVec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::displayThirdLine(clock_t time)
{
    std::cout << "Time to process a range of " << myVector.size()
            << " elements with std::vector : " << (float)time * 100 / CLOCKS_PER_SEC << " us" << std::endl;
}

void    PmergeMe::displayLastLine(clock_t time)
{
    std::cout << "Time to process a range of " << myDeque.size()
            << " elements with std::deque : " << (float)time * 100 / CLOCKS_PER_SEC << " us" << std::endl;
}

void    PmergeMe::mergeInsertionSort()
{
    std::vector<std::pair<int, int> > vecPairs;
    std::vector<int>    sortedVec;
    std::deque<std::pair<int, int> > deqPairs;
    std::deque<int>    sortedDeq;
    displayFirstLine();

    //! VECTOR part
    clock_t vecStart = clock();
    vecPairs = pairAndSortElementVec(myVector);
    sortedVec = extractFirstEleVec(vecPairs);

    displaySecondLine(sortedVec);
    displayThirdLine(clock() - vecStart);

    //! DEQUE part
    clock_t deqStart = clock();
    deqPairs = pairAndSortElementDeq(myDeque);
    sortedDeq = extractFirstEleDeq(deqPairs);
    displayLastLine(clock() - deqStart);
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