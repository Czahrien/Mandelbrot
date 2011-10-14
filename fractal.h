//
//  fractal.h
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#ifndef Mandelbrot_fractal_h
#define Mandelbrot_fractal_h
class fractal {
public: // *structors
    fractal( int _window_width, int _window_height );
    fractal( const fractal& f );
    virtual ~fractal();
public: 
    virtual void draw_fractal() = 0;
    void center( int x, int y );
    void center( const long double& x, const long double& y );
    void zoom_in( const long double& amt );
    void zoom_out( const long double& amt );
public:
    double gamma() const;
    void set_gamma( const double& g );
    const double ** get_fractal();
protected:
    int _window_width;
    int _window_height;
    int _iters;
    long double _center_x;
    long double _center_y;
    long double _res;
    double _g;
    double **_pixels;
    int _redraw;
};
#endif
