#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class   Fixed {
    private:
        int fixedPoint;
        static  const   int fractionalBits;

    public:
        Fixed(); // default contructor 
        ~Fixed();  // destructor
        Fixed( const Fixed& other );  // copy constructor
        Fixed&  operator=( const Fixed& other );  // copy assingnement operator
        Fixed( const int p );
        Fixed( const float p );


        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        bool    operator>( const Fixed& other ) const;
        bool    operator>=( const Fixed& other ) const;
        bool    operator<( const Fixed& other ) const;
        bool    operator<=( const Fixed& other ) const;
        bool    operator==( const Fixed& other ) const;
        bool    operator!=( const Fixed& other ) const;

        Fixed   operator+( const Fixed& other ) const;
        Fixed   operator-( const Fixed& other ) const;
        Fixed   operator*( const Fixed& other ) const;
        Fixed   operator/( const Fixed& other ) const;

        Fixed&  operator++();
        Fixed&  operator--();
        Fixed  operator++(int);
        Fixed  operator--(int);

        static   Fixed&  min(Fixed& a, Fixed& b);
        static   Fixed&  max(Fixed& a, Fixed& b);

        static   const Fixed&  min(const Fixed& a, const Fixed& b);
        static   const Fixed&  max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif