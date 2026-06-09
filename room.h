#ifndef ROOM_H
#define ROOM_H
#include <GL/glut.h>

// Texture Variables
extern GLuint floorTex, outWallTex, inWallTex, woodTex, windowTex, pcTex, clockTex, doorTex, sofaTex, bedsheetTex, emonTex, ranaTex, rugTex, keyboardTex, mouseTex, curtainTex;

// Appliance & Light States
extern bool lightOn;
extern bool fanOn;
extern bool pcOn;
extern bool acOn;
extern bool projLightOn; 
extern bool lampOn;      

// Door States
extern bool doorOpen;
extern float doorAngle;

// AC Animation States
extern float acFanAngle;
extern float mistOffset;

// NEW: Window & Curtain States
extern bool curtainOpen;
extern float curtainOffset;
extern bool windowOpen;
extern float windowOffset;

void drawRoom();
void initRoom();
void reshapeRoom(int w, int h);

#endif
