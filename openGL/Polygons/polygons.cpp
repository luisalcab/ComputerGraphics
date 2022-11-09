#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;
int n = 5;

/* Initial display-window size. */
GLsizei winWidth = 400, winHeight = 400;
GLuint regHex;

class screenPt
{
private:
    GLint x, y;
public:
    /* Default Constructor: initializes coordinate position to (0, 0).*/
    screenPt ( ) {
	x = y = 0;
    }
    void setCoords (GLint xCoord, GLint yCoord) {
	x = xCoord;
	y = yCoord;
    }
    GLint getx ( ) const {
	return x;
    }
    GLint gety ( ) const {
	return y;
    }
};

static void init (void)
{
    screenPt hexVertex, circCtr;
    GLdouble theta;
    GLint k;
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    /* Set circle center coordinates. */
    circCtr.setCoords (winWidth / 2, winHeight / 2);
    glClearColor (1.0, 1.0, 1.0, 0.0); //    Display-window color = white.
    regHex = glGenLists (1); // Get an identifier for the display list.
    glNewList (regHex, GL_COMPILE);
    glColor3f (r, g, b);  // Set fill color for hexagon to red.
    glBegin (GL_POLYGON);
    for (k = 0; k < n; k++) {
        theta = TWO_PI * k / n;
        hexVertex.setCoords (circCtr.getx ( ) + 150 * cos (theta),
                    circCtr.gety ( ) + 150 * sin (theta));
        glVertex2i (hexVertex.getx ( ), hexVertex.gety ( ));
    }

    glEnd ( );
    glEndList ( );
}

void regHexagon (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glCallList (regHex);
    glFlush ( );
}

void winReshapeFcn (int newWidth, int newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ( );
    gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
    glClear (GL_COLOR_BUFFER_BIT);
}

void mousePtPlot (GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
        if (n < 12){
            n ++;
            glClear (GL_COLOR_BUFFER_BIT);
            init();
            glFlush ( );
        } else {
            n = 5;
            glClear (GL_COLOR_BUFFER_BIT);
            init();
            glFlush ( );
        }
    }
    glFlush ( );
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Polygons");
    init ( );
    glutDisplayFunc (regHexagon);
    glutReshapeFunc (winReshapeFcn);
    glutMouseFunc (mousePtPlot);
    glutMainLoop ( );
    return 0;
}
