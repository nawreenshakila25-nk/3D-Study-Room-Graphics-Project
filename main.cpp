#include <GL/glut.h>
#include "room.h"


void displayAnimation();
void update(int value);
void keyboard(unsigned char key, int x, int y);


void display()
{

    drawRoom();


    displayAnimation();


    glutSwapBuffers();
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


    glutInitWindowSize(1000, 700);
    glutCreateWindow("3D Study Room - Complete Team Project");


    initRoom();


    glutDisplayFunc(display);
    glutReshapeFunc(reshapeRoom);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}
