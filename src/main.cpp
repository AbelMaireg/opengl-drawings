#include <GL/glut.h>
#include <cmath>

class Point
{
  public:
    int x, y;

    Point (int x, int y) : x (x), y (y) {}
};

void
drawLineDDA (Point p1, Point p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int steps = std::max (abs (dx), abs (dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = p1.x;
    float y = p1.y;

    glBegin (GL_POINTS);
    for (int i = 0; i <= steps; ++i)
        {
            glVertex2i (round (x), round (y));
            x += xInc;
            y += yInc;
        }
    glEnd ();
}

void
display ()
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1.0, 0.0, 0.0);

    drawLineDDA (Point (50, 50), Point (300, 300));

    glFlush ();
}

void
init ()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glPointSize (2.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0, 500, 0, 500);
}

int
main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200, 200);
    glutCreateWindow ("DDA Line Drawing Algorithm");
    init ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
