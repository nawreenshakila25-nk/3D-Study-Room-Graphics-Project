#include <GL/glut.h>
#include <math.h>
#include "furniture.h"
#include "room.h"

float fanAngle = 0;
float clockAngle = 0;
float doorAngle = 0.0f;

float acFanAngle = 0.0f;
float mistOffset = 0.0f;
float curtainOffset = 1.0f;
float windowOffset = 0.0f;

void drawFan() {
    glPushMatrix();
    glTranslatef(6.5f, 2.6f, 0.0f); glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); glTranslatef(-1.5f, 0.0f, -1.0f);
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix(); glScalef(0.6f, 0.05f, 0.6f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.4f, 0.0f); glScalef(0.1f, 0.8f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.8f, -0.1f); glScalef(0.3f, 0.3f, 0.4f); solidCube(1.0f); glPopMatrix();
    glTranslatef(0.0f, 0.8f, 0.15f); glRotatef(fanAngle, 0, 0, 1);
    glColor3f(0.8f, 0.8f, 0.8f);
    glPushMatrix(); glScalef(0.15f, 0.15f, 0.05f); solidCube(1.0f); glPopMatrix();
    for(int i = 0; i < 4; i++) {
        glPushMatrix(); glRotatef(i * 90.0f, 0, 0, 1); glTranslatef(0.0f, 0.3f, 0.0f); glScalef(0.1f, 0.5f, 0.02f); solidCube(1.0f); glPopMatrix();
    }
    glPopMatrix();
}

void drawClock()
{
    glPushMatrix();
    glTranslatef(7.9f, 5.0f, 0.0f);
    glRotatef(-90.0f, 0, 1, 0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, clockTex);
    glColor3f(1.0f, 1.0f, 1.0f);

    float r = 0.8f;
    glBegin(GL_POLYGON);
    glNormal3f(0, 0, 1);
    for(int i = 0; i < 360; i += 5) {
        float rad = i * 3.14159265f / 180.0f;
        glTexCoord2f(0.5f + 0.5f * cos(rad), 0.5f + 0.5f * sin(rad));
        glVertex3f(r * cos(rad), r * sin(rad), 0.0f);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);

    
    glTranslatef(0.0f, 0.0f, 0.02f);
    glRotatef(-clockAngle, 0, 0, 1);

    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.65f);
    glEnd();
    glLineWidth(1.0f);

    glPopMatrix();
}

void displayAnimation() {
    drawFan();
    drawClock();
}

void update(int value) {
    if(fanOn) fanAngle += 5;
    clockAngle += 1;

    if(doorOpen && doorAngle < 90.0f) doorAngle += 2.0f;
    if(!doorOpen && doorAngle > 0.0f) doorAngle -= 2.0f;

    if(windowOpen && windowOffset < 1.0f) windowOffset += 0.02f;
    if(!windowOpen && windowOffset > 0.0f) windowOffset -= 0.02f;

    if(curtainOpen && curtainOffset < 1.0f) curtainOffset += 0.02f;
    if(!curtainOpen && curtainOffset > 0.0f) curtainOffset -= 0.02f;

    if (acOn) {
        acFanAngle += 12.0f;
        mistOffset += 0.02f;
        if (acFanAngle > 360.0f) acFanAngle -= 360.0f;
        if (mistOffset > 1.0f) mistOffset = 0.0f;
    }

    if(fanAngle > 360) fanAngle -= 360;
    if(clockAngle > 360) clockAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
