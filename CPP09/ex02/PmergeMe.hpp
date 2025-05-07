#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <deque>
# include <ctime>

class PmergeMe
{
    private :
        std::vector<int> myVector;
        std::deque<int> myDeque;
        int             vecStruggle;
        int             deqStruggle;

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

    public :

        PmergeMe(std::vector<int> vec);
        ~PmergeMe();
        void    mergeInsertionSort();
        void    displayFirstLine();
        void    displaySecondLine(std::vector<int>& sortedVec);
        void    displayThirdLine(clock_t time);
        void    displayLastLine(clock_t time);

        //! VECTOR FUNCTIONS
        void    fillVector(std::vector<int> vec);
        std::vector<std::pair<int, int> >   pairAndSortElementVec(std::vector<int> vec);
        std::vector<int>    extractFirstEleVec(std::vector<std::pair<int, int> > pairs);

        //! DEQUE FUNCTIONS
        void    fillDeque(std::vector<int> vec);
        std::deque<std::pair<int, int> >   pairAndSortElementDeq(std::deque<int> deq);
        std::deque<int>     extractFirstEleDeq(std::deque<std::pair<int, int> > pairs);

        class InvalidInputException : public std::exception {
            const char* what() const throw();
        };
};

std::vector<int>   parseInput(std::vector<std::string>& vec);
std::vector<int>   convertStringVec(std::vector<std::string>& stringVec);
void    checkDigit(std::string& str);
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);


#endif