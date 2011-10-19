//
//  complex.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/12/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include "complex.h"

void test(void);

complex::complex() : _x(0.0), _y(0.0) {}

complex::complex( const double& x, const double& y) : _x(x), _y(y) {}

complex::complex(const double& x) : _x(x), _y(0.0) {}

complex::complex(const complex& c) : _x(c._x), _y(c._y) {}

complex::~complex() {}

double complex::real() const {
    return _x;
}

double complex::imag() const {
    return _y;
}

void complex::set_real( const double& r ) {
    _x = r;
}

void complex::set_imag( const double& i ) {
    _y = i;
}

complex complex::operator*(const complex &rhs) const {
    double real = _x * rhs._x - _y * rhs._y;
    double imag = _x * rhs._y + _y * rhs._x;
    return complex(real,imag);
}

complex complex::operator/(const complex &rhs) const {
    //rhs is the denominator, find it's conjugate
    complex conj(rhs._x,-rhs._y);
    complex top = *this * conj;
    double bottom = rhs._x * rhs._x + rhs._y * rhs._y;
    top._x /= bottom;
    top._y /= bottom;
    return top;
}

complex complex::operator+(const complex &rhs) const {
    return complex(_x+rhs._x,_y+rhs._y);
}

complex complex::operator-(const complex &rhs) const {
    return complex(_x-rhs._x,_y-rhs._y);
}

complex& complex::operator=(const complex& rhs) {
    if( this != &rhs ) {
        _x = rhs._x;
        _y = rhs._y;
    }
    return *this;
}

complex& complex::operator+=(const complex& rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return *this;
}

complex& complex::operator-=(const complex& rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    return *this;
}

complex& complex::operator*=(const complex& rhs) {
    double real = _x * rhs._x - _y * rhs._y;
    _y = _x * rhs._y + _y * rhs._x;
    _x = real;
    return *this;
}

complex& complex::operator/=(const complex &rhs) {
    //rhs is the denominator, find it's conjugate
    complex conj(rhs._x,-rhs._y);
    complex top = *this * conj;
    double bottom = rhs._x * rhs._x + rhs._y * rhs._y;
    top._x /= bottom;
    top._y /= bottom;
    _x = top._x;
    _y = top._y;
    return *this;
}

complex complex::operator-() const {
    return complex(-_x,-_y);
}

std::ostream& operator<<( std::ostream& out, const complex& z ) { 
    out << "(" << z._x << "+" << z._y << "i)";
    return out;
}

void test(void) {
    complex c1(3.0,4.0), c2(1.0,-1.0);
    std::cout << c1 << "*" << c2 << "=" << c1*c2 << std::endl;
    std::cout << c1 << "+" << c2 << "=" << c1+c2 << std::endl;
    std::cout << c1 << "-" << c2 << "=" << c1-c2 << std::endl;
    std::cout << c1 << "/" << c2 << "=" << c1/c2 << std::endl;
    std::cout << complex(2,6)/complex(4,1) << std::endl;
    std::cout << complex(3,4)/complex(5,-1) << std::endl;
    std::cout << "-" << c2 << "=" << -c2 << std::endl;
    std::cout << (c1 = c1 * c1 + c2) << std::endl;
    std::cout << (c1 = c1 * c1 + c2) << std::endl;
    std::cout << (c1 = c1 * c1 + c2) << std::endl;
    complex c(-0.35,-1.95);
    complex z(c);
    complex z2 = c;
    std::cout << c << " " << z << std::endl;
    //std::cout << (z = z*z + c ) << std::endl;
    std::cout << (z = z*z) << " " << (z += c) << std::endl;
    std::cout << (z2 *= z2) << " " << (z2 += c) << std::endl; 
}
