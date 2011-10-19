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

// complex represents a complex number in the form (x+yi)
class complex {
public: // *structors
    complex();
    complex(const double& x, const double& y);
    complex(const double& x);
    complex(const complex& c);
    ~complex();
public:
    double real() const;
    double imag() const;
    void set_real(const double& r);
    void set_imag(const double& i);
public: // operator overloads involving complex numbers
    complex operator+(const complex& rhs) const;
    complex operator-(const complex& rhs) const;
    complex operator*(const complex& rhs) const;
    complex operator/(const complex& rhs) const;
    complex operator-() const;
    complex& operator+=(const complex& rhs);
    complex& operator-=(const complex& rhs);
    complex& operator*=(const complex& rhs);
    complex& operator/=(const complex& rhs);
    complex& operator=(const complex& rhs);
    int operator<(const complex& rhs) const;
    int operator>(const complex& rhs) const;
    int operator<=(const complex& rhs) const;
    int operator>=(const complex& rhs) const;
    int operator==(const complex& rhs) const;
    int operator!=(const complex& rhs) const;
public:
    // Real portion of the complex number
    double _x;
    // Imaginary portion of the complex number
    double _y;
};

std::ostream& operator<<( std::ostream& out, const complex& z );

#endif
