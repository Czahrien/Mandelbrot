//
//  complex.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/12/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_complex_h
#define Mandelbrot_complex_h
#include <iostream>
class complex {
public: // *structors
    complex();
    complex(long double x, long double y);
    complex(long double x);
    complex(const complex& c);
    ~complex();
public:
    long double real();
    long double imag();
    void set_real(long double r);
    void set_imag(long double i);
public: // operator overloads involving complex numbers
    complex operator+(const complex& rhs);
    complex operator-(const complex& rhs);
    complex operator*(const complex& rhs);
    complex operator/(const complex& rhs);
    complex operator-();
    complex& operator+=(const complex& rhs);
    complex& operator-=(const complex& rhs);
    complex& operator*=(const complex& rhs);
    complex& operator/=(const complex& rhs);
    complex& operator=(const complex& rhs);
public:
    // Real portion of the complex number
    long double _x;
    // Imaginary portion of the complex number
    long double _y;
};

std::ostream& operator<<( std::ostream& out, const complex& z );

#endif
