#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed {
    private:
        int fixedPoint;
        static  const   int rawBits;

    public:
        Fixed(); // default contructor 
        ~Fixed();  // destructor
        Fixed(const Fixed& other);  // copy constructor
        Fixed&  operator=(const Fixed& other);  // copy assingnement operator
        Fixed(const int p);
        Fixed(const float p);

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif