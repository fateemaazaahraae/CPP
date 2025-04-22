# include "BitcoinExchange.hpp"

//! O.C.F
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    dataBase = other.dataBase;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        dataBase = other.dataBase;
    return *this;
}

//! Exceptions
const char* BitcoinExchange::ArgException::what() const throw()
{
    return "Error: Invalid Argument\nUsage: ./btc input.txt";
}

const char* BitcoinExchange::inputFileException::what() const throw()
{
    return "Error: Cannot open the Input file";
}

const char* BitcoinExchange::dataFileException::what() const throw()
{
    return "Error: Cannot open the data.csv";
}

const char* BitcoinExchange::fileFormatException::what() const throw()
{
    return "Error: Bad input.txt format";
}

const char* BitcoinExchange::negativeException::what() const throw()
{
    return "Error: not a positive number.";
}

const char* BitcoinExchange::outOfRangeException::what() const throw()
{
    return "Error: too large a number.";
}

const char* BitcoinExchange::badInputException::what() const throw()
{
    return "Error: bad input";
}

const char* BitcoinExchange::noEarlierDateException::what() const throw()
{
    return "Error: No earlier date";
}

const char* BitcoinExchange::dateValueException::what() const throw()
{
    return "Error: Invalid date(year, month or day) value";
}

//! Member Functions
void    BitcoinExchange::StoreData()
{
    std::ifstream   dataFile("data.csv");
    std::string     line;
    std::pair<std::string, std::string> pair;
    
    if (!dataFile.is_open())
    throw BitcoinExchange::dataFileException();
    getline(dataFile, line);
    while (true)
    {
        getline(dataFile, line);
        if (line.empty())
            break;
        pair = std::make_pair(line.substr(0, line.find_first_of(',')), line.substr(line.find_first_of(',') + 1, line.length()));
        dataBase.insert(pair);
    }
}

bool    BitcoinExchange::countPipe(std::string& line)
{
    int count = 0;

    for (size_t i = 0; i < line.length(); i++)
        if (line[i] == '|')
            count++;
    if (count == 1)
        return true;
    return false;
}

bool    BitcoinExchange::checkMinus(std::string line)
{
    int count = 0;

    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == '-')
        {
            count++;
            if (i == 0 || i == line.length() - 1 || !isdigit(line[i - 1]) || !isdigit(line[i + 1]))
                return false;
        }
    }
    if (count != 2)
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(std::string date)
{
    if (!checkMinus(date))
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
        return false;
    if (m < 1 || m > 12 || d < 1 || d > 31 || y > 2025)
        throw dateValueException();
    return true;
}


void    BitcoinExchange::parseFirstDate(std::string first)
{
    if (isValidDate(first) == false)
        throw badInputException();    
}

bool    BitcoinExchange::checkDouble(std::string str)
{
    //! still need a lot of work
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            count++;
            if (i == 0 || i == str.length() - 1 || !isdigit(str[i - 1]) || !isdigit(str[i + 1]))
                return false;
        }
        if (!isdigit(str[i]) && str[i] != '.')
            return false;
    }
    if (count > 1)
        return false;
    return true;
}

void    BitcoinExchange::parseSecondDate(std::string second)
{
    if (checkDouble(second) == false)
        throw badInputException();
    double n = std::atof(second.c_str());
    if (n > 1000)
        throw outOfRangeException();
}

std::string BitcoinExchange::trim(std::string str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

void    BitcoinExchange::displayInfo(std::string& line)
{
    std::pair<std::string, std::string> p1;
    std::map<std::string, std::string>::iterator it;

    if (countPipe(line) == false)
        throw fileFormatException();
    p1.first = trim(line.substr(0, line.find_first_of('|')));
    p1.second = trim(line.substr(line.find_first_of('|') + 1));
    parseFirstDate(p1.first);
    
    if (p1.second.empty())
        throw badInputException();
    parseSecondDate(p1.second);
    it = dataBase.lower_bound(p1.first);
    if (it == dataBase.end() || it->first != p1.first)
    {
        if (it == dataBase.begin())
            throw noEarlierDateException();
        --it;
    }
    float value = std::atof(p1.second.c_str());
    float rate = std::atof(it->second.c_str());
    float multipl = rate * value;
    std::cout << p1.first << " => " << atof(p1.second.c_str()) << " = " << multipl << std::endl;
}
