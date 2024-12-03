#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class test {
    private:
        int i;

    public:
        test( const test& other);
        test();
        ~test();
        test& operator=(const test& other);
        int    get();
        void    set(int y);
};

#endif