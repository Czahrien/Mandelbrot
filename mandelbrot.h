//
//  mandelbrot.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_mandelbrot_h
#define Mandelbrot_mandelbrot_h
#include "fractal.h"

class mandelbrot : public fractal {
public:
    mandelbrot();
    mandelbrot( int window_width, int window_height );
    mandelbrot( const mandelbrot& m );
    ~mandelbrot();
public:
    virtual void draw_fractal();
};


#endif
