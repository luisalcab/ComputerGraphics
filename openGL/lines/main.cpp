// First Program in OpenGL
/*
Author: 
Luis Alberto Alcántara Cabrales A01634185

Description:
This program draws a line using the OpenGL library,
the Glut library, the GLEW library and the algorithm 
of Bresenham.

Date: 8/11/2022
*/

#include <GL/glut.h>
#include <iostream>
using namespace std;

// Structure to hold the coordinates of a point
struct Point {
    float x;
    float y;
};

// Global Variables to hold the coordinates of the two points
Point points [10] = {
    {1,2}, {100,20},
    {10,200}, {50,10},
    {300,300}, {10,10},
    {200,300}, {250,50},
    {350,350}, {100, 300}
};

void init (void)
{
    // Set display-window color to white.
    glClearColor (1.0, 1.0, 1.0, 0.0);
    // Set projection parameters.
    glMatrixMode (GL_PROJECTION);
    // Set clipping area's left, right, bottom, top.
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void pointsLine (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_POINTS);

    // Printing lines using points
    float x1, y1, x2, y2;
    for (int i = 0; i < 10; i+=2) {
        x1 = points[i].x;
        y1 = points[i].y;
        x2 = points[i+1].x;
        y2 = points[i+1].y;

        float dx = abs(x2 - x1);
        float dy = abs(y2 - y1);
        float sx = x1 < x2 ? 1 : -1;
        float sy = y1 < y2 ? 1 : -1;
        float err = dx - dy;

        while (true) {
            glVertex2i (x1, y1);
            if (x1 == x2 && y1 == y2) break;
            float e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    glEnd ();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);    // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);    // Set display mode.
    glutInitWindowPosition (50, 100);    // Set top-left display-window position.
    glutInitWindowSize (400, 400);    // Set display-window width and height.
    glutCreateWindow ("An Example OpenGL Program"); // Create display window.
    init ( ); // Execute initialization procedure.
    glutDisplayFunc (pointsLine);    // Send graphics to display window.
    glutMainLoop ( );    // Display everything and wait.
    return 0;
}
