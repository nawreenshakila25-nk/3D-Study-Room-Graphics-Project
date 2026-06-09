#include <GL/glut.h>
#include <stdlib.h>
#include "room.h"

bool lightOn = true;
bool fanOn = true;
bool pcOn = true;
bool acOn = false;
bool doorOpen = false;
bool projLightOn = true;
bool lampOn = true;

extern float cameraX, cameraY, cameraZ;
extern float roomRotX, roomRotY, roomRotZ;

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

        case 'l': case 'L': lightOn = !lightOn; break;
        case 'v': case 'V': projLightOn = !projLightOn; break;
        case 't': case 'T': lampOn = !lampOn; break;
        case 'p': case 'P': pcOn = !pcOn; break;
        case 'f': case 'F': fanOn = !fanOn; break;
        case 'a': case 'A': acOn = !acOn; break;
        case 'o': case 'O': doorOpen = !doorOpen; break;


        case 'c': cameraX++; break;
        case 'C': cameraX--; break;
        case 'd': cameraY++; break;
        case 'D': cameraY--; break;
        case 'e': cameraZ++; break;
        case 'E': cameraZ--; break;


        case 'x': roomRotX += 5.0f; break;
        case 'X': roomRotX -= 5.0f; break;
        case 'y': roomRotY += 5.0f; break;
        case 'Y': roomRotY -= 5.0f; break;
        case 'z': roomRotZ += 5.0f; break;
        case 'Z': roomRotZ -= 5.0f; break;

        case 'q': case 'Q': case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}
