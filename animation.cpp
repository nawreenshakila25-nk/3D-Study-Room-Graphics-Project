#include <GL/glut.h>

float fanAngle = 0;
float clockAngle = 0;

/* Rotating Fan */
void drawFan()
{
    glPushMatrix();

    glTranslatef(-0.5, 0.0, 0.0);

    glRotatef(fanAngle, 0, 0, 1);

    for(int i = 0; i < 4; i++)
    {
        glRotatef(90, 0, 0, 1);

        glBegin(GL_TRIANGLES);

        glVertex2f(0, 0);
        glVertex2f(0.1, 0.5);
        glVertex2f(-0.1, 0.5);

        glEnd();
    }

    glPopMatrix();
}

/* Rotating Clock */
void drawClock()
{
    glPushMatrix();

    glTranslatef(0.5, 0.0, 0.0);

    glRotatef(clockAngle, 0, 0, 1);

    glBegin(GL_LINES);

    glVertex2f(0, 0);
    glVertex2f(0, 0.4);

    glEnd();

    glPopMatrix();
}

/* Display animation */
void displayAnimation()
{
    drawFan();
    drawClock();
}

/* Update animation */
void update(int value)
{
    fanAngle += 2;
    clockAngle += 1;

    if(fanAngle > 360)
        fanAngle = 0;

    if(clockAngle > 360)
        clockAngle = 0;

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}
