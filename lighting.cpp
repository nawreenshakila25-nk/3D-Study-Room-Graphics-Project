#include <GL/glut.h>


extern bool lightOn;


void toggleLight()
{
    lightOn = !lightOn;

    if(lightOn)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
    }

    glutPostRedisplay();
}
