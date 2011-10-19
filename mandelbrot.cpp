//
//  mandelbrot.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include <cmath>
#include "mandelbrot.h"

mandelbrot::mandelbrot() : fractal() {}

mandelbrot::mandelbrot( int window_width, int window_height ) : fractal( window_width, window_height ) {}

mandelbrot::mandelbrot( const mandelbrot& m ) : fractal(m) {}

mandelbrot::~mandelbrot() {}

void mandelbrot::draw_fractal() {
    complex c(0.0,0.0);
    double l2 = log(2);
    int i = 0;
    c._y = (-_window_height/2)*_res + _center_y;
    for( int row = 0; row < _window_height; ++row ) {
        c._x = (-_window_width/2)*_res + _center_x;
        for( int col = 0; col < _window_width; ++col ) {
            complex z(c);
            i = 0;
            while( z._x * z._x + z._y * z._y < 4.0 && i < _iters  ) {
                z = z * z + c;
                ++i;
            }

            double d = -1.0;
            if( i < _iters ) {
                z = z * z + c;
                z = z * z + c;
                d = (i + 3 - log(log(z._x * z._x + z._y * z._y))/l2)/_iters;
            }

            _pixels[row][col] = pow(d,_g);
            c._x += _res;
        }
        c._y += _res;
    }    
}
