#include <GL/glut.h>

/* Function from lighting.cpp */
void toggleLight();

/* Keyboard controls */
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'l':
            toggleLight();
            break;

        case 'q':
            exit(0);
            break;
    }
}
