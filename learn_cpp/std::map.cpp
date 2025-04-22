# include <iostream>
# include <map>
# include <utility>

void    add_func(std::map<std::string, float>& myMap)
{
    std::string key;
    float       value;

    std::cout << "Enter student's name :";
    getline(std::cin, key);
    std::cout << "Enter student's grade :";
    std::cin >> value;
    myMap.insert(std::make_pair(key, value));
}

void    find_func(std::map<std::string, float>& myMap)
{
    std::map<std::string, float>::iterator it;
    std::string user;

    std::cout << "Enter the student's name you want to search for: ";
    getline(std::cin, user);
    it = myMap.find(user);
    if (it != myMap.end())
        std::cout << "The student FOUND" << std::endl;
    else
        std::cout << "The student NOT FOUND" << std::endl;
}

void    erase_func(std::map<std::string, float>& myMap)
{
    std::string user;

    std::cout << "Enter the student's name you want to erase: ";
    getline(std::cin, user);
    myMap.erase(user);
}

void    show_func(std::map<std::string, float>& myMap)
{
    if (myMap.empty())
        std::cout << "The map is EMPTY" << std::endl;
    else
        for (std::map<std::string, float>::iterator it = myMap.begin(); it != myMap.end(); it++)
            std::cout << "Pair[" << it->first << "] : " << it->second << std::endl;
}

int main()
{
    std::map<std::string, float> myMap;
    std::string input;

    while (true)
    {
        std::cout << "What do you want to do? (add / find / erase / show / exit): ";
        getline(std::cin, input);
        if (input == "exit")
            break;
        else if (input == "add")
            add_func(myMap);
        else if (input == "find")
            find_func(myMap);
        else if (input == "erase")
            erase_func(myMap);
        else if (input == "show")
            show_func(myMap);
        else
            std::cout << "UNKNOWN command" << std::endl;
    }
}