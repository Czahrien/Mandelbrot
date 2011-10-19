//
//  julia.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/18/11.
//  Copyright 2011 RIT. All rights reserved.
//


#include <cmath>
#include "julia.h"
#include "complex.h"

julia::julia() : fractal() {}

julia::julia( int window_width, int window_height, const complex& c ) : fractal( window_width, window_height ), _c(c) {}

julia::julia( const julia& j ) : fractal(j), _c(j._c) {}

julia::~julia() {}

void julia::draw_fractal() {
    complex c;
    double l2 = log(2);
    int i = 0;
    c._y = (-_window_height/2)*_res + _center_y;
    for( int row = 0; row < _window_height; ++row ) {
        c._x = (-_window_width/2)*_res + _center_x;
        for( int col = 0; col < _window_width; ++col ) {
            complex z(c);
            i = 0;
            while( z._x * z._x + z._y * z._y < 4.0 && i < _iters  ) {
                z = z * z + _c;
                ++i;
            }
            
            double d = -1.0;
            if( i < _iters ) {
                z = z * z + _c;
                z = z * z + _c;
                d = (i + 3 - log(log(z._x * z._x + z._y * z._y))/l2)/_iters;
            }
            
            _pixels[row][col] = pow(d,_g);
            c._x += _res;
        }
        c._y += _res;
    }    
}
