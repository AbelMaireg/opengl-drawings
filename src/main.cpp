#include <GL/glut.h>
#include <cmath>

void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(0.0f, 0.0f, 0.5f, 1000);
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Circle in OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
