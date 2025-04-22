#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <exception>
# include <fstream>
# include <string>
# include <utility>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <bits/stdc++.h>

class BitcoinExchange 
{
    private :
        std::map<std::string, std::string> dataBase;

    public :

        //! O.C.F
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange&    operator=(const BitcoinExchange& other);
        
        //! Exceptions
        //? for argument
        class ArgException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for input file opening error
        class inputFileException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for data file opening error
        class dataFileException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for file format "data | value"
        class fileFormatException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for negative value
        class negativeException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for value greater than 1000
        class outOfRangeException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for invalid date format
        class badInputException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for earlier date
        class noEarlierDateException : public std::exception
        {
            public :
                const char* what() const throw();
        };
        //? for invalid date value ex: 2300-55-90
        class dateValueException : public std::exception
        {
            public :
                const char* what() const throw();
        };

        //! Member Functions
        void    StoreData();
        void    displayInfo(std::string& line);
        bool    countPipe(std::string& line);
        void    parseFirstDate(std::string first);
        void    parseSecondDate(std::string second);
        bool    isValidDate(std::string line);
        bool    checkMinus(std::string line);
        std::string trim(std::string str);
        bool    checkDouble(std::string str);
};

#endif