//
//  fractal.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/13/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include "fractal.h"

fractal::fractal() : _window_width(800), _window_height(600), _iters(1000), _center_x(0.0), _center_y(0.0), _res(0.005),  _g(2.5), _redraw(1) {}

fractal::fractal( int window_width, int window_height ) : _window_width(window_width), _window_height(window_height), _iters(1000), _center_x(0.0), _center_y(0.0), _res(0.005),  _g(2.5), _redraw(1) {
    _pixels = new double*[_window_height];
    for( int i = 0; i < _window_height; ++i ) {
        _pixels[i] = new double[_window_width];
    }
}

fractal::fractal( const fractal& f ) : _window_width(f._window_width), _window_height(f._window_height), _iters(f._iters), _center_x(f._center_x), _center_y(f._center_y), _res(f._res),  _g(f._g){
    _pixels = new double*[_window_height];
    for( int i = 0; i < _window_height; ++i ) {
        _pixels[i] = new double[_window_width];
        for( int j = 0; j < _window_width; ++j ) {
            _pixels[i][j] = f._pixels[i][j];
        }
    }
}

fractal::~fractal() {
    for( int i = 0; i < _window_height; ++i ) {
        delete _pixels[i];
    }
    delete _pixels;
}

void fractal::center( int x, int y ) {
    y = _window_height - 1 - y;
    _center_x = (x - _window_width/2)*_res + _center_x;
    _center_y = (y - _window_height/2)*_res + _center_y;
    _redraw = 1;
}

void fractal::center( const double& x, const double& y ) {
    _center_x = x;
    _center_y = y;
    _redraw = 1;
}

void fractal::zoom_in( const double& amt ) {
    _res /= amt;
    _redraw = 1;
}

void fractal::zoom_out( const double& amt ) {
    _res *= amt;
    _redraw = 1;
}

double fractal::gamma() const {
    return _g;
}

void fractal::set_gamma( const double& g ) {
    _g = g;
}

int fractal::iters() const {
    return _iters;
}

void fractal::set_iters( int i ) {
    _iters = i;
}

void fractal::resize( int width, int height ) {
    for( int i = 0; i < _window_height; ++i ) {
        delete[] _pixels[i];
    }
    delete[] _pixels;
    _window_width = width;
    _window_height = height;
    _pixels = new double*[_window_height];
    for( int i = 0; i < _window_height; ++i ) {
        _pixels[i] = new double[_window_width];
    }
    _redraw = 1;
}

const double ** fractal::get_fractal() {
    if( _redraw ) {
        draw_fractal();
        _redraw = 0;
    }
    return (const double**)_pixels;
}

std::ostream& operator<<( std::ostream& out, const fractal& f ) {
    out << "Center: (" << f._center_x << "," << f._center_y << ")" << std::endl;
    out << "Res: " << f._res << std::endl;
    out << f._iters << " " << f._g << std::endl;
    out << "Window Size: " << f._window_width << "*" << f._window_height << std::endl;
    return out;
}

