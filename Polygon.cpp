#include <windows.h>
#include <GL/glut.h>


void initGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(-0.3f, 0.3f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.6f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Polygon");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}