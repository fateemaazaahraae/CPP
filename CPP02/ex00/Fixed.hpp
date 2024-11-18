#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class   Fixed {
    private:
        int fixedPoint;
        static  const   int rawBits;

    public:
        Fixed(); // default contructor 
        ~Fixed();  // destructor
        Fixed(const Fixed& other);  // copy constructor
        Fixed&  operator=(const Fixed& other);  // copy assingnement operator

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};

#endif