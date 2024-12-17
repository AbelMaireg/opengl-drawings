#include <GL/glut.h>
#include <cmath>
#include <utility>

class Point
{
  public:
    int x, y;

    Point(int x, int y) : x(x), y(y)
    {
    }
};

void drawCircle(Point p1, int radius)
{
    int x = 0;
    int y = -radius;
    int p = 0.25 - radius;

    glBegin(GL_POINTS);
    while (x < -y)
    {
        if (p > 0)
        {
            y += 1;
            p += 2 * y + 2;
        }
        p += 2 * x + 1;

        glVertex2i(p1.x + x, p1.y + y);
        glVertex2i(p1.x + x, p1.y - y);
        glVertex2i(p1.x - x, p1.y + y);
        glVertex2i(p1.x - x, p1.y - y);
        glVertex2i(p1.x + y, p1.y + x);
        glVertex2i(p1.x + y, p1.y - x);
        glVertex2i(p1.x - y, p1.y + x);
        glVertex2i(p1.x - y, p1.y - x);

        x++;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);

    drawCircle(Point(0, 0), 9);

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
