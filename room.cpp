#include <windows.h>
#include <GL/glut.h>

float cameraX = 0.0f;
float cameraY = 4.0f;
float cameraZ = 15.0f;

void drawFloor()
{
    glColor3f(0.55f, 0.27f, 0.07f);

    glBegin(GL_QUADS);

    glVertex3f(-8.0f, 0.0f, -8.0f);
    glVertex3f( 8.0f, 0.0f, -8.0f);
    glVertex3f( 8.0f, 0.0f,  8.0f);
    glVertex3f(-8.0f, 0.0f,  8.0f);

    glEnd();
}

void drawCeiling()
{

    glColor3f(0.95f, 0.95f, 0.95f);

    glBegin(GL_QUADS);

    glVertex3f(-8.0f, 7.0f, -8.0f);
    glVertex3f( 8.0f, 7.0f, -8.0f);
    glVertex3f( 8.0f, 7.0f,  8.0f);
    glVertex3f(-8.0f, 7.0f,  8.0f);

    glEnd();
}

void drawWalls()
{
    glColor3f(0.88f, 0.86f, 0.80f);

    glBegin(GL_QUADS);

    glVertex3f(-8.0f, 0.0f, -8.0f);
    glVertex3f( 8.0f, 0.0f, -8.0f);
    glVertex3f( 8.0f, 7.0f, -8.0f);
    glVertex3f(-8.0f, 7.0f, -8.0f);

    glEnd();


    glBegin(GL_QUADS);

    glVertex3f(-8.0f, 0.0f, -8.0f);
    glVertex3f(-8.0f, 0.0f,  8.0f);
    glVertex3f(-8.0f, 7.0f,  8.0f);
    glVertex3f(-8.0f, 7.0f, -8.0f);

    glEnd();


    glBegin(GL_QUADS);

    glVertex3f(8.0f, 0.0f, -8.0f);
    glVertex3f(8.0f, 0.0f,  8.0f);
    glVertex3f(8.0f, 7.0f,  8.0f);
    glVertex3f(8.0f, 7.0f, -8.0f);

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        cameraX, cameraY, cameraZ,
        0.0f, 3.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    drawFloor();
    drawCeiling();
    drawWalls();

    glutSwapBuffers();
}


void reshape(int w, int h)
{
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        60.0,
        (float)w / (float)h,
        1.0,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(0.75f, 0.85f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 50);

    glutCreateWindow("3D Study Room - Step 1");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}

