//
//  fractal.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_fractal_h
#define Mandelbrot_fractal_h
#include <iostream>
#include "complex.h"
class fractal {
public: // *structors
    fractal( int _window_width, int _window_height );
    fractal( const fractal& f );
    virtual ~fractal();
public: 
    virtual void draw_fractal() = 0;
    void center( int x, int y );
    void center( const double& x, const double& y );
    void zoom_in( const double& amt );
    void zoom_out( const double& amt );
public:
    double gamma() const;
    void set_gamma( const double& g );
    int iters() const;
    void set_iters( int i );
    const double ** get_fractal();
protected:
    int _window_width;
    int _window_height;
    int _iters;
    double _center_x;
    double _center_y;
    double _res;
    double _g;
    double **_pixels;
    int _redraw;
    friend std::ostream& operator<<( std::ostream& out, const fractal& f );
};

std::ostream& operator<<( std::ostream& out, const fractal& f );
#endif
