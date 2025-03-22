#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_data
{
    int     x;
    char    c;
}   Data;


class Serializer 
{
    private:
        ~Serializer();
    public:
        static  uintptr_t serialize(Data* ptr);
        static  Data* deserialize(uintptr_t raw);
};

#endif