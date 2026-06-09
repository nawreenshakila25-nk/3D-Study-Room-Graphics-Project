#include <windows.h>
#include <GL/glut.h>

float cameraX = 0.0f;
float cameraY = 4.0f;
float cameraZ = 15.0f;

void setupLighting()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat position[] = {0.0f, 6.0f, 2.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

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

void drawSky()
{
    glDisable(GL_LIGHTING);

    glColor3f(0.4f, 0.75f, 1.0f);

    glBegin(GL_QUADS);

    glVertex3f(-5.0f, 0.0f, -12.0f);
    glVertex3f( 5.0f, 0.0f, -12.0f);
    glVertex3f( 5.0f, 8.0f, -12.0f);
    glVertex3f(-5.0f, 8.0f, -12.0f);

    glEnd();

    glEnable(GL_LIGHTING);
}

void drawWindow()
{
    glColor3f(0.6f, 0.85f, 1.0f);

    glBegin(GL_QUADS);

    glVertex3f(-2.0f, 2.0f, -7.95f);
    glVertex3f( 2.0f, 2.0f, -7.95f);
    glVertex3f( 2.0f, 5.0f, -7.95f);
    glVertex3f(-2.0f, 5.0f, -7.95f);

    glEnd();

    glDisable(GL_LIGHTING);

    glColor3f(0.45f, 0.22f, 0.05f);

    glLineWidth(4);

    glBegin(GL_LINES);

    glVertex3f(-2.0f, 2.0f, -7.9f);
    glVertex3f( 2.0f, 2.0f, -7.9f);

    glVertex3f( 2.0f, 2.0f, -7.9f);
    glVertex3f( 2.0f, 5.0f, -7.9f);

    glVertex3f( 2.0f, 5.0f, -7.9f);
    glVertex3f(-2.0f, 5.0f, -7.9f);

    glVertex3f(-2.0f, 5.0f, -7.9f);
    glVertex3f(-2.0f, 2.0f, -7.9f);

    glVertex3f(0.0f, 2.0f, -7.9f);
    glVertex3f(0.0f, 5.0f, -7.9f);

    glVertex3f(-2.0f, 3.5f, -7.9f);
    glVertex3f( 2.0f, 3.5f, -7.9f);

    glEnd();

    glEnable(GL_LIGHTING);
}

void drawLightSource()
{
    glPushMatrix();

    glDisable(GL_LIGHTING);

    glTranslatef(0.0f, 6.2f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.8f);

    glutSolidSphere(0.25f, 20, 20);

    glEnable(GL_LIGHTING);

    glPopMatrix();
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

    drawSky();
    drawFloor();
    drawCeiling();
    drawWalls();
    drawWindow();
    drawLightSource();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    if(h == 0)
        h = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        60.0,
        (float)w/(float)h,
        1.0,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(0.75f,0.85f,1.0f,1.0f);

    glEnable(GL_DEPTH_TEST);

    setupLighting();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(1000,700);

    glutCreateWindow("3D Study Room - Step 3");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
