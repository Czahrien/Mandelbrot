//
//  rational.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/19/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_rational_h
#define Mandelbrot_rational_h
#include <iostream>

class rational {
public: //*structors
    rational();
    rational(const long& num, const long& den);
    rational(const long& num );
    ~rational();
public: //accessors and mutators
    long numerator() const;
    long denominator() const;
    void set_numerator( const long& num );
    void set_denominator( const long& den );
    int is_negative() const;
    void simplify();
public:
    rational operator+( const rational& rhs ) const;
    rational operator-( const rational& rhs ) const;
    rational operator*( const rational& rhs ) const;
    rational operator/( const rational& rhs ) const;
    rational& operator+=( const rational& rhs );
    rational& operator-=( const rational& rhs );
    rational& operator*=( const rational& rhs );
    rational& operator/=( const rational& rhs );
    rational& operator=( const rational& rhs );
    int operator<( const rational& rhs ) const;
    int operator<=( const rational& rhs ) const;
    int operator>( const rational& rhs ) const;
    int operator>=( const rational& rhs ) const;
    int operator==( const rational& rhs ) const;
    int operator!=( const rational& rhs ) const;
public:
    friend std::ostream& operator<<( std::ostream& out, const rational& r);
public:
    long _n;
    long _d;
};

long gcd( long a, long b );
std::ostream& operator<<( std::ostream& out, const rational& r );
int main();
#endif
