#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
static float shift = 0;

void boatMove()
{
    shift += 0.01;
    //if(shift > 200)
    // shift = 0;
    shift = (shift > 200) ? 0 : shift;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.3, 0.3, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 18);
    glVertex2f(150, 18);
    glVertex2f(150, 0);

    glEnd();

    glPushMatrix();
    // we want to draw moving boat

    boatMove();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(45 + shift, 20);
    glVertex2f(5 + shift, 20);
    glVertex2f(15 + shift, 10);
    glVertex2f(35 + shift, 10);

    glEnd();



    glColor3f(0.160, 0.658, 0.203);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 30);
    glVertex2f(25 + shift, 25);
    glVertex2f(17.943 + shift, 25.019);

    glEnd();


    // fourth regular shape is octagon
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 25.0);
    glVertex2f(25 + shift, 20);
    glVertex2f(23 + shift, 20);
    glVertex2f(23 + shift, 25);

    glEnd();

    glPopMatrix();

    glFlush();
}


void init(void)
{
    glClearColor(0.10, 0.10, 0.10, 0.0);
    glOrtho(0, 100.0, 0, 100.0, 0, 100.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}