//
//  main.cpp
//  Mandelbrot
//
//  Created by Benjamin Mayes on 10/12/11.
//  Copyright 2011 RIT. All rights reserved.
//

#include <iostream>
#include <cmath>
#ifdef __APPLE__
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif
#include "complex.h"

using namespace std;

typedef struct _color {
    float r;
    float g;
    float b;
} color;

double mandelbrot[600][800];
int scene_change = 1;



long double res = 0.005;
long double center_x = 0.0;
long double center_y = 0.0;
int iters = 1000;
double g = 0.1;

#define WINDOW_HORIZONTAL_SIZE 800
#define WINDOW_VERTICAL_SIZE 600

void glut_init(void);
void glut_display(void);
void test(void);
color hsv_to_rgb( double h );

void glut_init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void glut_display(void) {
    static int up = 0;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if( scene_change ) {
        for ( int row = 0; row < WINDOW_VERTICAL_SIZE; ++row ) {
            for( int col = 0; col < WINDOW_HORIZONTAL_SIZE; ++col ) {
                int i = 0;
                complex c((col-WINDOW_HORIZONTAL_SIZE/2)*res+center_x,(row-WINDOW_VERTICAL_SIZE/2)*res+center_y);
                complex z(c);
                while( i < iters && z._x * z._x + z._y * z._y < 4.0 ) {
                    z = z*z + c;
                    ++i;
                }
                if( i < iters ) {
                    z = z*z + c;
                    z = z*z + c;
                    double j = i + 3 - log(log(z._x * z._x + z._y * z._y))/log(2);
                    if( j < 0.0 ) j = 0.0;
                    mandelbrot[row][col] = j/iters;
                } else {
                    mandelbrot[row][col] = -1.0;
                }
            }
        }
        scene_change = 0;
    }
    glBegin(GL_POINTS);
    for( int row = 0; row < WINDOW_VERTICAL_SIZE; ++row) {
        for( int col = 0; col < WINDOW_HORIZONTAL_SIZE; ++col ) {
            double *d = &mandelbrot[row][col];
            color c = {0,0,0};
            if( *d != -1.0 ) {
                c = hsv_to_rgb(3600*pow(*d,g));
            }
            glColor3f(c.r,c.g,c.b);
            glVertex2d(col, row);
        }
    }
    if( up ) {
        g *= 1.01;
        if( g > 3.0 ) up = 0;
    } else {
        g /= 1.01;
        if( g < 0.05 ) up = 1;
    }
    glEnd();
    glutSwapBuffers();
}

void mouse( int button, int state, int x, int y ) {
    if( state == GLUT_UP ) {
        switch( button ) {
            case GLUT_LEFT_BUTTON: 
                center_x = (x - WINDOW_HORIZONTAL_SIZE/2)*res + center_x;
                center_y = (WINDOW_VERTICAL_SIZE/2-y)*res + center_y;
                scene_change = 1;
                break;
            case GLUT_RIGHT_BUTTON:                
                center_x = (x - WINDOW_HORIZONTAL_SIZE/2)*res + center_x;
                center_y = (WINDOW_VERTICAL_SIZE/2-y)*res + center_y;
                res /= 2;
                scene_change = 1;
                break;
        }
        if( scene_change ) 
            glutPostRedisplay();

    }
}

void keyboard( unsigned char key, int x, int y ) {
    switch( key ) {
        case ']'://GLUT_WHEEL_UP:
            g *= 1.1;
            //scene_change = 1;
            break;
        case '['://GLUT_WHEEL_DOWN:
            g /= 1.1;
            //scene_change = 1;
            break;
        case '-':
            res *= 2;
            scene_change = 1;
            break;
        case '+':
            res /= 2;
            scene_change = 1;
            break;
    }
    glutPostRedisplay();
}

void timer( int value ) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
}

color hsv_to_rgb( double h ) {
    h = fmod(h,360);
    color c = {0.0,0.0,0.0};
    double hprime = h / 60;
    double x = (1 - abs(fmod(hprime, 2) - 1));
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

int main (int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Mandelbrot");
    glutDisplayFunc(glut_display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1000/60, timer, 0);
    glut_init();
    glutMainLoop();
    return 0;
}

