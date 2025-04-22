# include "BitcoinExchange.hpp"

int main(int ac, char**av)
{
    try
    {
        if (ac != 2)
            throw BitcoinExchange::ArgException();
        std::ifstream   infile(av[1]);
        std::string     line;
        BitcoinExchange data;

        if(!infile.is_open())
            throw BitcoinExchange::inputFileException();
        data.StoreData();
        getline(infile, line);
        if (line != "date | value")
        {
            infile.close();
            throw BitcoinExchange::fileFormatException();
        }
        while (getline(infile, line))
        {
            try
            {
                data.displayInfo(line);
            }
            catch(std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        infile.close();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}