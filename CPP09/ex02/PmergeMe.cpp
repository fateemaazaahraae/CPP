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

bool comparePairs(const Pair& a, const Pair& b)
{
    return a.first < b.first;
}

std::vector<Pair> PmergeMe::pairAndSortElementVec(std::vector<int> vec)
{
    std::vector<Pair> pairs;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);
    return pairs;
}


std::vector<int> PmergeMe::extractFirstElements(const std::vector<Pair>& pairs)
{
    std::vector<int> result;
    for (size_t i = 0; i < pairs.size(); ++i)
        result.push_back(pairs[i].first);
    return result;
}

std::vector<int> PmergeMe::extractSecondElements(const std::vector<Pair>& pairs)
{
    std::vector<int> result;
    for (size_t i = 0; i < pairs.size(); ++i)
        result.push_back(pairs[i].second);
    return result;
}

std::vector<size_t> PmergeMe::getJacobInsertionOrderVec(size_t n)
{
    std::vector<size_t> order;
    if (n == 0)
        return order;

    std::vector<size_t> jacob;
    jacob.push_back(1);
    size_t j1 = 1, j2 = 0;

    while (1)
    {
        size_t next = j1 + 2 * j2;
        if (next >= n)
            break;
        jacob.push_back(next);
        j2 = j1;
        j1 = next;
    }

    std::vector<bool> inserted(n, false);
    for (size_t i = 0; i < jacob.size(); ++i) 
    {
        size_t j = jacob[i];
        if (j < n && !inserted[j])
        {
            order.push_back(j);
            inserted[j] = true;
        }
        size_t start = (i == 0) ? 0 : jacob[i - 1] + 1;
        for (ssize_t k = j - 1; k >= static_cast<ssize_t>(start); --k)
        {
            if (!inserted[k])
            {
                order.push_back(k);
                inserted[k] = true;
            }
        }
    }
    for (size_t i = 0; i < n; ++i)
        if (!inserted[i])
            order.push_back(i);
    return order;
}

void PmergeMe::insertWithJacobOrderVec(std::vector<int>& S, const std::vector<int>& B)
{
    std::vector<size_t> order = getJacobInsertionOrderVec(B.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int value = B[order[i]];
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), value);
        S.insert(pos, value);
    }
}

void PmergeMe::insertStragglerVec(std::vector<int>& S, int straggler)
{
    std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler);
    S.insert(pos, straggler);
}

void    PmergeMe::mergeInsertionSortVec(std::vector<int>& vec)
{
    if (vec.size() < 1)
        return;

    std::vector<Pair> vecPairs = pairAndSortElementVec(vec);
    std::vector<int> S = extractFirstElements(vecPairs);
    std::vector<int> B = extractSecondElements(vecPairs);

    bool hasStraggler = vec.size() % 2 != 0;
    int straggler = hasStraggler ? vec.back() : -1;

    insertWithJacobOrderVec(S, B);

    if (hasStraggler)
        insertStragglerVec(S, straggler);

    vec = S;
}

//! END VECTOR


//! DEQUE FUNCTIONS
void    PmergeMe::fillDeque(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        myDeque.push_back(vec[i]);
}

std::deque<Pair> PmergeMe::pairAndSortElementDeq(std::deque<int> vec)
{
    std::deque<Pair> pairs;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);

    return pairs;
}


std::deque<int> PmergeMe::extractFirstElementsDeq(const std::deque<Pair>& pairs)
{
    std::deque<int> result;
    for (size_t i = 0; i < pairs.size(); ++i)
        result.push_back(pairs[i].first);
    return result;
}

std::deque<int> PmergeMe::extractSecondElementsDeq(const std::deque<Pair>& pairs)
{
    std::deque<int> result;
    for (size_t i = 0; i < pairs.size(); ++i)
        result.push_back(pairs[i].second);
    return result;
}

std::deque<size_t> PmergeMe::getJacobInsertionOrderDeq(size_t n)
{
    std::deque<size_t> order;
    if (n == 0)
        return order;

    std::deque<size_t> jacob;
    jacob.push_back(1);
    size_t j1 = 1, j2 = 0;

    while (1)
    {
        size_t next = j1 + 2 * j2;
        if (next >= n)
            break;
        jacob.push_back(next);
        j2 = j1;
        j1 = next;
    }

    std::vector<bool> inserted(n, false);
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        size_t j = jacob[i];
        if (j < n && !inserted[j])
        {
            order.push_back(j);
            inserted[j] = true;
        }

        size_t start = (i == 0) ? 0 : jacob[i - 1] + 1;
        for (ssize_t k = j - 1; k >= static_cast<ssize_t>(start); --k)
        {
            if (!inserted[k])
            {
                order.push_back(k);
                inserted[k] = true;
            }
        }
    }
    for (size_t i = 0; i < n; ++i)
        if (!inserted[i])
            order.push_back(i);
    return order;
}

void PmergeMe::insertWithJacobOrderDeq(std::deque<int>& S, const std::deque<int>& B)
{
    std::deque<size_t> order = getJacobInsertionOrderDeq(B.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int value = B[order[i]];
        std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), value);
        S.insert(pos, value);
    }
}

void PmergeMe::insertStragglerDeq(std::deque<int>& S, int straggler)
{
    std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), straggler);
    S.insert(pos, straggler);
}

void    PmergeMe::mergeInsertionSortDeq(std::deque<int>& deq)
{
    if (deq.size() < 1)
        return;

    std::deque<Pair> deqPairs = pairAndSortElementDeq(deq);
    std::deque<int> S = extractFirstElementsDeq(deqPairs);
    std::deque<int> B = extractSecondElementsDeq(deqPairs);

    bool hasStraggler = deq.size() % 2 != 0;
    int straggler = hasStraggler ? deq.back() : -1;

    insertWithJacobOrderDeq(S, B);

    if (hasStraggler)
        insertStragglerDeq(S, straggler);
    deq = S;
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

void    PmergeMe::displayThirdLine(unsigned long time)
{
    std::cout << "Time to process a range of " << myVector.size()
            << " elements with std::vector : " << time << " us" << std::endl;
}

void    PmergeMe::displayLastLine(unsigned long time)
{
    std::cout << "Time to process a range of " << myDeque.size()
            << " elements with std::deque : " << time << " us" << std::endl;
}

void    PmergeMe::mergeInsertionSort()
{
	struct timeval 						tv;
    unsigned long   startVec;
    unsigned long   endVec;
    unsigned long   startDeq;
    unsigned long   endDeq;

    displayFirstLine();

    //! VECTOR part
    gettimeofday(&tv, NULL);
    startVec = 1000000 * tv.tv_sec + tv.tv_usec;

    mergeInsertionSortVec(myVector);

    gettimeofday(&tv, NULL);
    endVec = 1000000 * tv.tv_sec + tv.tv_usec;

    displaySecondLine(myVector);
    displayThirdLine(endVec - startVec);

    //! DEQUE part
    gettimeofday(&tv, NULL);
    startDeq = 1000000 * tv.tv_sec + tv.tv_usec;

    mergeInsertionSortDeq(myDeque);

    gettimeofday(&tv, NULL);
    endDeq = 1000000 * tv.tv_sec + tv.tv_usec;
    displayLastLine(endDeq - startDeq);
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


