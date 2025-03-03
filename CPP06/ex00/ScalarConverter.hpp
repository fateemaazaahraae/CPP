#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <climits>

class ScalarConverter 
{
    private:
        ScalarConverter();
    public :
        // ~ScalarConverter();
        // ScalarConverter(const ScalarConverter& other);
        // ScalarConverter&    operator=(const ScalarConverter& other);

        static void convert(std::string input);
        static void impossibleCast();

        //! check the datatype
        static bool isChar(std::string input);
        static bool isInt(std::string input);
        static bool isFloat(std::string input);
        static bool isDouble(std::string input);

        //! Conversion
        static void castToChar(std::string input);
        static void castToInt(std::string input);
        static void castToFloat(std::string input);
        static void castToDouble(std::string input);
};

#endif