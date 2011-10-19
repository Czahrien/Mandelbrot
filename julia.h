//
//  julia.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/18/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_julia_h
#define Mandelbrot_julia_h
#include "fractal.h"

class julia : public fractal {
public:
    julia();
    julia( int window_width, int window_height, const complex& c );
    julia( const julia& m );
    ~julia();
public:
    virtual void draw_fractal();
protected:
    complex _c;
};


#endif
