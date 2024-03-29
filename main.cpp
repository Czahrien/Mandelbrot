//
//  main.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/12/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include "mandelbrot.h"
#include "julia.h"

#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include "color.h"
#include "complex.h"

using namespace std;

int WINDOW_HORIZONTAL_SIZE =  800;
int WINDOW_VERTICAL_SIZE =  600;

mandelbrot m(WINDOW_HORIZONTAL_SIZE,WINDOW_VERTICAL_SIZE);//, complex(-0.8,0.156));

void glut_init(void);
void glut_display(void);
void keyboard(unsigned char,int,int);
void mouse(int,int,int,int);
void timer(int);
void test(void);

void glut_init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_HORIZONTAL_SIZE, 0.0, WINDOW_VERTICAL_SIZE);
}

void glut_display(void) {
    static int up = 0;
    static unsigned int i = 0;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBegin(GL_POINTS);
    const double ** pixels = m.get_fractal();
    i++;
    for( int row = 0; row < WINDOW_VERTICAL_SIZE; ++row) {
        const double* r = pixels[row];
        for( int col = 0; col < WINDOW_HORIZONTAL_SIZE; ++col ) {
            color c = {0,0,0};
            if( *r > 0 ) {
                c = rgb_from_hue(1800*(0.001*i+*r));
            }
            r++;
            glColor3f(c.r,c.g,c.b);
            glVertex2d(col, row);
        }
    }
    /*double g = m.gamma();
    if( up ) {
        m.set_gamma(g * 1.01);
        if( g > 3.0 ) up = 0;
    } else {
        m.set_gamma(g / 1.01);
        if( g < 0.05 ) up = 1;
    }*/
    glEnd();
    glutSwapBuffers();
}

void mouse( int button, int state, int x, int y ) {
    if( state == GLUT_UP ) {
        switch( button ) {
            case GLUT_LEFT_BUTTON: 
                m.center(x, y);
                glutPostRedisplay();
                break;
            case GLUT_RIGHT_BUTTON:                
                m.center(x, y);
                m.zoom_in(2.0);
                glutPostRedisplay();
                break;
        }

    }
}

void keyboard( unsigned char key, int x, int y ) {
    switch( key ) {
        case ']':
            m.set_gamma(m.gamma() * 1.1);
            break;
        case '[':
            m.set_gamma(m.gamma() / 1.1);
            break;
        case '-':
            m.zoom_out(2.0);
            break;
        case '+':
            m.zoom_in(2.0);
            break;
        case ';':
            m.set_iters(m.iters() - 250);
            cout << m.iters() << endl;
            break;
        case '\'':
            m.set_iters(m.iters() + 250);
            cout << m.iters();
            break;
        case 'd':
            cout << m << endl;
            break;
    }
    glutPostRedisplay();
}

void timer( int value ) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}



int main (int argc, char ** argv)
{
    if( argc == 3 ) {
        stringstream ss( stringstream::in | stringstream::out );
        ss.str( argv[1] );
        ss >> WINDOW_HORIZONTAL_SIZE; 
        ss.clear();
        ss.str( argv[2] );
        ss >> WINDOW_VERTICAL_SIZE; 
 
        if( WINDOW_HORIZONTAL_SIZE <= 0 && WINDOW_VERTICAL_SIZE <= 0 ) {
            cerr << "Usage: " << argv[0] << " [width] [height]" << endl;
            return 1;
        }       
        m.resize(WINDOW_HORIZONTAL_SIZE, WINDOW_VERTICAL_SIZE);
    }
    m.set_gamma(0.25);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_HORIZONTAL_SIZE, WINDOW_VERTICAL_SIZE);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Fractal Viewer");
    glutDisplayFunc(glut_display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000/60, timer, 0);
    glut_init();
    glutMainLoop();
    return 0;
}

