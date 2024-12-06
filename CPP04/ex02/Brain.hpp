#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
    private:
        std::string ideas[100];

    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain&  operator=(const Brain& other);

        void    setIdea(std::string idea, int index);
        std::string&    getIdea(int index);

};

#endif