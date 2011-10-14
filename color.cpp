//
//  color.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include <cmath>
#include "color.h"

color rgb_from_hue( double h ) {
    h = fmod(h,360);
    color c = {0.0,0.0,0.0};
    double hprime = h / 60;
    double x = (1 - fabs(fmod(hprime, 2) - 1));
    switch( (int)hprime ) {
        case 0:
            c.r = 1.0;
            c.g = x;
            break;
        case 1:
            c.r = x;
            c.g = 1.0;
            break;
        case 2:
            c.g = 1.0;
            c.b = x;
            break;
        case 3:
            c.g = x;
            c.b = 1.0;
            break;
        case 4:
            c.b = 1.0;
            c.r = x;
            break;
        case 5:
            c.b = x;
            c.r = 1.0;
            break;
        default:
            break;
    }
    return c;
}
