//
//  rational.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/19/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include "rational.h"

rational::rational() : _n(1), _d(1) {
    
}

rational::rational(const long& num, const long& den) : _n(num), _d(den) {
    simplify();
}

rational::rational(const long& num ) : _n(num), _d(1) {

}

rational::~rational() {}

long rational::numerator() const {
    return _n;
}

long rational::denominator() const {
    return _d;
}

void rational::set_numerator( const long& num ) {
    _n = num;
    simplify();
}

void rational::set_denominator( const long& den ) {
    _d = den;
    simplify();
}

int rational::is_negative() const {
    return _n < 0 ^ _d < 0;
}

void rational::simplify() {
    long div = gcd(_n,_d);
    _n /= div;
    _d /= div;
}

rational rational::operator+( const rational& rhs ) const {
    long n = _n * rhs._d + rhs._n * _d;
    long d =  _d * rhs._d;
    return rational(n,d);    
}
rational rational::operator-( const rational& rhs ) const {
    long n = _n * rhs._d - rhs._n * _d;
    long d =  _d * rhs._d;
    return rational(n,d);  
}
rational rational::operator*( const rational& rhs ) const {
    long n = _n * rhs._n;
    long d = _d * rhs._d;
    return rational(n,d);
}

rational rational::operator/( const rational& rhs ) const {
    long n = _n * rhs._d;
    long d = _d * rhs._n;
    return rational(n,d);
}

rational& rational::operator+=( const rational& rhs ) {
    _n = _n * rhs._d + rhs._n * _d;
    _d =  _d * rhs._d;
    simplify();
    return *this;
}

rational& rational::operator-=( const rational& rhs ) {
    _n = _n * rhs._d - rhs._n * _d;
    _d =  _d * rhs._d;
    simplify();
    return *this;
}

rational& rational::operator*=( const rational& rhs ) {
    _n = _n * rhs._n;
    _d = _d * rhs._d;
    simplify();
    return *this;
}

rational& rational::operator/=( const rational& rhs ) {
    long n = _n * rhs._d;
    _d = _d * rhs._n;
    _n = n;
    simplify();
    return *this;
}

rational& rational::operator=( const rational& rhs ) {
    _n = rhs._n;
    _d = rhs._d;
}

int rational::operator<( const rational& rhs ) const {
    return (*this - rhs).is_negative();
}

int rational::operator<=( const rational& rhs ) const {
    return *this < rhs || *this == rhs;
}
            
int rational::operator>( const rational& rhs ) const {
    return (rhs - *this).is_negative();
}
            
int rational::operator>=( const rational& rhs ) const {
    return *this > rhs || *this == rhs;
}
            
int rational::operator==( const rational& rhs ) const {
    return (_n == rhs._n && _d == rhs._d);
}
            
int rational::operator!=( const rational& rhs ) const {
    return (_n != rhs._n || _d != rhs._d);
}

long gcd( long a, long b ) {
    while( a && b ) {
        if( a > b ) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a > b ? a : b;
}

std::ostream& operator<<( std::ostream& out, const rational& r ) {
    out << r._n;
    if( r._d > 1 ) {
        out << '/' << r._d;
    }
    return out;
}
