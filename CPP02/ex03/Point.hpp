#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point( float x1, float y1 );
        Point( const Point& other );
        Point&  operator=( const Point& other );
        ~Point();

        const Fixed&   getX( void ) const;
        const Fixed&   getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed   areaCalculator(Point const x, Point const y, Point const z);

#endif