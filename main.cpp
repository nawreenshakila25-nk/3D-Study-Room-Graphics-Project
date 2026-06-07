#include <GL/glut.h>

/* Functions from other files */
void displayAnimation();
void update(int value);
void keyboard(unsigned char key, int x, int y);

/* Main display */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    displayAnimation();

    glutSwapBuffers();
}

/* Main function */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("3D Study Room");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}
