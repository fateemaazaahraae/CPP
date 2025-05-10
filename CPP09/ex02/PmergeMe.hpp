#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <deque>
# include <ctime>
# include <sys/time.h>

typedef std::pair<int, int> Pair;

class PmergeMe
{
    private :
        std::vector<int> myVector;
        std::deque<int> myDeque;

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

    public :

        PmergeMe(std::vector<int> vec);
        ~PmergeMe();
        void    mergeInsertionSort();
        void    displayFirstLine();
        void    displaySecondLine(std::vector<int>& sortedVec);
        void    displayThirdLine(unsigned long time);
        void    displayLastLine(unsigned long time);
        
        //! VECTOR FUNCTIONS
        void    fillVector(std::vector<int> vec);
        std::vector<size_t> getJacobInsertionOrderVec(size_t n);
        std::vector<Pair>   pairAndSortElementVec(std::vector<int> vec);
        std::vector<int>    extractFirstElements(const std::vector<Pair>& pairs);
        std::vector<int>    extractSecondElements(const std::vector<Pair>& pairs);
        void    insertWithJacobOrderVec(std::vector<int>& S, const std::vector<int>& B);
        void    insertStragglerVec(std::vector<int>& S, int straggler);
        void    mergeInsertionSortVec(std::vector<int>& vec);

        //! DEQUE FUNCTIONS
        void    fillDeque(std::vector<int> vec);
        void    mergeInsertionSortDeq(std::deque<int>& deq);
        void    insertStragglerDeq(std::deque<int>& S, int straggler);
        std::deque<Pair>    pairAndSortElementDeq(std::deque<int> vec);
        std::deque<int> extractFirstElementsDeq(const std::deque<Pair>& pairs);
        std::deque<int> extractSecondElementsDeq(const std::deque<Pair>& pairs);
        std::deque<size_t> getJacobInsertionOrderDeq(size_t n);
        void    insertWithJacobOrderDeq(std::deque<int>& S, const std::deque<int>& B);


        class InvalidInputException : public std::exception {
            const char* what() const throw();
        };
};

std::vector<int>   parseInput(std::vector<std::string>& vec);
std::vector<int>   convertStringVec(std::vector<std::string>& stringVec);
void    checkDigit(std::string& str);
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);


#endif