#ifndef ROOM_H
#define ROOM_H
#include <GL/glut.h>


extern GLuint floorTex, outWallTex, inWallTex, woodTex, windowTex, pcTex, clockTex, doorTex, sofaTex, bedsheetTex, emonTex, ranaTex, rugTex, keyboardTex, mouseTex;


extern bool lightOn;
extern bool fanOn;
extern bool pcOn;
extern bool acOn;
extern bool projLightOn; 
extern bool lampOn;      


extern bool doorOpen;
extern float doorAngle;


extern float acFanAngle;
extern float mistOffset;

void drawRoom();
void initRoom();
void reshapeRoom(int w, int h);

#endif
