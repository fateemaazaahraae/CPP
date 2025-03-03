# include "ScalarConverter.hpp"

//! CHAR tools
bool ScalarConverter::isChar(std::string input)
{
    return (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

void ScalarConverter::castToChar(std::string input) 
{
    char c = input[0];

    if (isprint(c))
        std::cout << "Char: '" << c << "'" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;

    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) 
              << static_cast<float>(c) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) 
              << static_cast<double>(c) << std::endl;
}

//! INT tools
bool    ScalarConverter::isInt(std::string input)
{
    int i = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;
    for (; input[i]; i++)
        if (!isdigit(input[i]))
            return false;
    return true;
}

void    ScalarConverter::castToInt(std::string input)
{
    long long num = atoll(input.c_str());

    if (num >= 32 && num <= 126)
        std::cout << "Char: '" << static_cast<char> (num) << "'" << std::endl;
    else if (num < -128 || num > 127)
        std::cout << "Char: impossible" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
    if (num < INT_MIN || num > INT_MAX)
        std::cout << "Int: impossible" << std::endl;
    else
        std::cout << "Int: " << num << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1)
              << static_cast<float> (num) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1)
              << static_cast<double> (num) << std::endl;
}

//! FLOAT tools
bool    ScalarConverter::isFloat(std::string input)
{
    int i = 0;
    int len = input.length();
    bool    digit = false;
    bool    dot = false;

    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    if (len < 2 || input[len - 1] != 'f')
        return false;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < len - 1)
    {
        if (isdigit(input[i]))
            digit = true;
        else if (input[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else
            return false;
        i++;
    }
    return digit;
}

void    ScalarConverter::castToFloat(std::string input)
{
    float num = atof(input.c_str());
    int numInt = static_cast<int> (num);

    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << input << std::endl;
        std::cout << "Double: " << input.substr(0, input.length() - 1) << std::endl;
        return;
    }
    if (numInt >= 32 && numInt <= 126)
        std::cout << "Char: '" << static_cast<char> (numInt) << "'" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
    if (numInt < INT_MIN || numInt > INT_MAX)
        std::cout << "Int: impossible" << std::endl;
    else
        std::cout << "Int: " << numInt << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << num << std::endl;

}

//! DOUBLE tools
bool    ScalarConverter::isDouble(std::string input)
{
    int i = 0;
    int len = input.length();
    bool    digit = false;
    bool    dot = false;

    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;
    if (len < 2)
        return false;
    if (input[0] == '-' || input[0] == '+')
        i++;
    while (i < len)
    {
        if (isdigit(input[i]))
            digit = true;
        else if (input[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
        }
        else
            return false;
        i++;
    }
    if (input[0] == '.' || input[1] == '.' || input[len - 1] == '.')
        return false;
    return digit;
}

void    ScalarConverter::castToDouble(std::string input)
{
    double num = atof(input.c_str());
    int numInt = static_cast<int> (num);

    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << input << "f" << std::endl;
        std::cout << "Double: " << input << std::endl;
        return;
    }
    if (numInt >= 32 && numInt <= 126)
        std::cout << "Char: '" << static_cast<char> (numInt) << "'" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
    if (numInt < INT_MIN || numInt > INT_MAX)
        std::cout << "Int: impossible" << std::endl;
    else
        std::cout << "Int: " << numInt << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << num << std::endl;
}

void    ScalarConverter::impossibleCast()
{
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;
    std::cout << "Float: impossible" << std::endl;
    std::cout << "Double: impossible" << std::endl;
}

void    ScalarConverter::convert(std::string input)
{
    if (isChar(input))
        castToChar(input);
    else if (isInt(input))
        castToInt(input);
    else if (isFloat(input))
        castToFloat(input);
    else if (isDouble(input))
        castToDouble(input);
    else
        impossibleCast();
}