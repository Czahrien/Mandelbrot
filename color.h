//
//  color.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_color_h
#define Mandelbrot_color_h
typedef struct _color {
    float r;
    float g;
    float b;
} color;

color rgb_from_hue( double );
#endif
