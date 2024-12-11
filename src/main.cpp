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

void drawLineDDA(Point p1, Point p2);
void drawLineBresenham(Point p1, Point p2);
void drawLineBresenhamV(Point p1, Point p2);

void drawLineDDA(Point p1, Point p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int steps = std::max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = p1.x;
    float y = p1.y;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i)
    {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void drawLineBresenham(Point p1, Point p2)
{
    if (abs(p2.x - p1.x) < abs(p2.y - p1.y))
    {
        drawLineBresenhamV(p1, p2);
        return;
    }

    if (p1.x > p2.x)
    {
        std::swap(p1.x, p2.x);
        std::swap(p1.y, p2.y);
    }

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int dir = dy > 0 ? 1 : -1;
    dy *= dir;

    if (dx != 0)
    {
        int p = 2 * dy - dx;

        glBegin(GL_POINTS);

        for (int x = p1.x, y = p1.y; x < p1.x + dx + 1; x++)
        {
            glVertex2i(x, y);

            if (p >= 0)
            {
                y += dir;
                p -= 2 * dx;
            }

            p += 2 * dy;
        }

        glEnd();
    }
}

void drawLineBresenhamV(Point p1, Point p2)
{
    if (p1.y > p2.y)
    {
        std::swap(p1.x, p2.x);
        std::swap(p1.y, p2.y);
    }

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int dir = dx > 0 ? 1 : -1;
    dx *= dir;

    if (dy != 0)
    {
        int p = 2 * dx - dy;

        glBegin(GL_POINTS);

        for (int y = p1.y, x = p1.x; y < p1.y + dy + 1; y++)
        {
            glVertex2i(x, y);

            if (p >= 0)
            {
                x += dir;
                p -= 2 * dy;
            }

            p += 2 * dx;
        }

        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    drawLineDDA(Point(0, 0), Point(10, 30));

    glColor3f(0.0, 1.0, 0.0);

    drawLineBresenham(Point(0, 0), Point(10, 30));
    drawLineBresenham(Point(0, 0), Point(30, 10));
    drawLineBresenham(Point(100, 100), Point(90, 70));
    drawLineBresenham(Point(100, 100), Point(70, 90));
    drawLineBresenham(Point(0, 100), Point(10, 70));
    drawLineBresenham(Point(0, 100), Point(30, 90));
    drawLineBresenham(Point(100, 0), Point(90, 30));
    drawLineBresenham(Point(100, 0), Point(70, 10));

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
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
