#include <windows.h>
#include <GL/glut.h>
#include "furniture.h"
#include "room.h"


extern float acFanAngle;
extern float mistOffset;
extern float curtainOffset;
extern float windowOffset;
extern GLuint keyboardTex, mouseTex, curtainTex;

void solidCube(float size) {
    float s = size / 2.0f;
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1); glTexCoord2f(0.0f, 0.0f); glVertex3f(-s, -s,  s); glTexCoord2f(1.0f, 0.0f); glVertex3f( s, -s,  s); glTexCoord2f(1.0f, 1.0f); glVertex3f( s,  s,  s); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s,  s,  s);
    glNormal3f(0, 0, -1); glTexCoord2f(1.0f, 0.0f); glVertex3f(-s, -s, -s); glTexCoord2f(1.0f, 1.0f); glVertex3f(-s,  s, -s); glTexCoord2f(0.0f, 1.0f); glVertex3f( s,  s, -s); glTexCoord2f(0.0f, 0.0f); glVertex3f( s, -s, -s);
    glNormal3f(0, 1, 0); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s,  s, -s); glTexCoord2f(0.0f, 0.0f); glVertex3f(-s,  s,  s); glTexCoord2f(1.0f, 0.0f); glVertex3f( s,  s,  s); glTexCoord2f(1.0f, 1.0f); glVertex3f( s,  s, -s);
    glNormal3f(0, -1, 0); glTexCoord2f(0.0f, 0.0f); glVertex3f(-s, -s, -s); glTexCoord2f(1.0f, 0.0f); glVertex3f( s, -s, -s); glTexCoord2f(1.0f, 1.0f); glVertex3f( s, -s,  s); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s, -s,  s);
    glNormal3f(1, 0, 0); glTexCoord2f(0.0f, 0.0f); glVertex3f( s, -s, -s); glTexCoord2f(0.0f, 1.0f); glVertex3f( s,  s, -s); glTexCoord2f(1.0f, 1.0f); glVertex3f( s,  s,  s); glTexCoord2f(1.0f, 0.0f); glVertex3f( s, -s,  s);
    glNormal3f(-1, 0, 0); glTexCoord2f(1.0f, 0.0f); glVertex3f(-s, -s, -s); glTexCoord2f(0.0f, 0.0f); glVertex3f(-s, -s,  s); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s,  s,  s); glTexCoord2f(1.0f, 1.0f); glVertex3f(-s,  s, -s);
    glEnd();
}

void drawTable() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 2.5f, 0.0f); glScalef(5.0f, 0.15f, 2.5f); solidCube(1.0f); glPopMatrix();
    float legX[4] = { -2.3f, 2.3f, -2.3f, 2.3f }, legZ[4] = { -1.1f, -1.1f, 1.1f, 1.1f };
    for (int i = 0; i < 4; i++) { glPushMatrix(); glTranslatef(legX[i], 1.25f, legZ[i]); glScalef(0.2f, 2.5f, 0.2f); solidCube(1.0f); glPopMatrix(); }
    glDisable(GL_TEXTURE_2D);
}

void drawChair() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 1.4f, 0.0f); glScalef(1.5f, 0.12f, 1.5f); solidCube(1.0f); glPopMatrix();
    float clX[4] = { -0.65f, 0.65f, -0.65f, 0.65f }, clZ[4] = { -0.65f, -0.65f, 0.65f, 0.65f };
    for (int i = 0; i < 4; i++) { glPushMatrix(); glTranslatef(clX[i], 0.7f, clZ[i]); glScalef(0.12f, 1.4f, 0.12f); solidCube(1.0f); glPopMatrix(); }
    glPushMatrix(); glTranslatef(-0.65f, 2.2f, -0.65f); glScalef(0.1f, 1.5f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.65f, 2.2f, -0.65f); glScalef(0.1f, 1.5f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 2.5f, -0.65f); glScalef(1.2f, 0.6f, 0.08f); solidCube(1.0f); glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawBookshelf() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 3.0f, -0.45f); glScalef(3.0f, 6.0f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-1.45f, 3.0f, 0.0f); glScalef(0.1f, 6.0f, 1.0f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(1.45f, 3.0f, 0.0f); glScalef(0.1f, 6.0f, 1.0f); solidCube(1.0f); glPopMatrix();
    float shelfHeights[4] = { 0.1f, 2.0f, 4.0f, 5.9f };
    for(int i=0; i<4; i++) { glPushMatrix(); glTranslatef(0.0f, shelfHeights[i], 0.0f); glScalef(2.8f, 0.1f, 0.9f); solidCube(1.0f); glPopMatrix(); }
    glDisable(GL_TEXTURE_2D);

    GLfloat bookColors[3][3] = { {0.7f, 0.1f, 0.1f}, {0.1f, 0.4f, 0.7f}, {0.2f, 0.6f, 0.2f} };
    for(int i = 0; i < 6; i++) { glColor3fv(bookColors[i % 3]); glPushMatrix(); glTranslatef(-1.0f + (i * 0.35f), 2.45f, 0.0f); glScalef(0.12f, 0.8f, 0.6f); solidCube(1.0f); glPopMatrix(); }
    for(int i = 0; i < 4; i++) { glColor3fv(bookColors[(i+1) % 3]); glPushMatrix(); glTranslatef(0.2f + (i * 0.3f), 4.45f, 0.1f); glScalef(0.12f, 0.8f, 0.6f); solidCube(1.0f); glPopMatrix(); }
}

void drawDesktopSetup() {
    GLfloat darkPlastic[] = { 0.15f, 0.15f, 0.15f, 1.0f }; glColor3fv(darkPlastic);
    glPushMatrix(); glTranslatef(0.0f, 2.575f, 0.0f); glScalef(0.8f, 0.02f, 0.5f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 2.85f, -0.15f); glScalef(0.1f, 0.5f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 3.5f, -0.1f); glScalef(2.2f, 1.3f, 0.08f); solidCube(1.0f); glPopMatrix();

    if(pcOn) {
        glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, pcTex); glColor3f(1.0f, 1.0f, 1.0f);
        GLfloat screenGlow[] = {0.8f, 0.8f, 0.8f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, screenGlow);
    } else {
        glDisable(GL_TEXTURE_2D); glColor3f(0.0f, 0.0f, 0.0f);
        GLfloat noEmission[] = {0.0f, 0.0f, 0.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);
    }
    glPushMatrix(); glTranslatef(0.0f, 3.5f, -0.05f); glScalef(2.0f, 1.1f, 0.02f); solidCube(1.0f); glPopMatrix();

    if(pcOn) { GLfloat noEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f }; glMaterialfv(GL_FRONT, GL_EMISSION, noEmission); glDisable(GL_TEXTURE_2D); }

    glColor3f(0.1f, 0.1f, 0.1f); glPushMatrix(); glTranslatef(1.8f, 3.2f, -0.2f); glScalef(0.7f, 1.3f, 1.5f); solidCube(1.0f); glPopMatrix();

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, keyboardTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 2.58f, 0.6f); glScalef(1.4f, 0.03f, 0.4f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, mouseTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.9f, 2.58f, 0.6f); glScalef(0.12f, 0.04f, 0.2f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);
}

void drawBed() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 0.5f, 0.0f); glScalef(4.0f, 1.0f, 7.0f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 1.8f, -3.4f); glScalef(4.0f, 2.6f, 0.2f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, bedsheetTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 1.3f, 0.1f); glScalef(3.8f, 0.7f, 6.6f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    glColor3f(0.95f, 0.95f, 0.95f);
    glPushMatrix(); glTranslatef(-0.9f, 1.75f, -2.6f); glScalef(1.6f, 0.25f, 1.0f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef( 0.9f, 1.75f, -2.6f); glScalef(1.6f, 0.25f, 1.0f); solidCube(1.0f); glPopMatrix();
}

void drawSofa() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 0.4f, 0.0f); glScalef(5.0f, 0.8f, 2.5f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, sofaTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 1.0f, -0.1f); glScalef(4.8f, 0.6f, 2.3f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 1.6f, -1.0f); glScalef(4.8f, 1.2f, 0.5f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);
}

void drawBedSideTable() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glScalef(1.3f, 1.5f, 1.3f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    glColor3f(0.85f, 0.7f, 0.2f);
    glPushMatrix(); glTranslatef(0.0f, 0.3f, 0.66f); glScalef(0.3f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, -0.3f, 0.66f); glScalef(0.3f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();

    glPushMatrix(); glTranslatef(0.2f, 0.75f, 0.0f);
    glColor3f(0.25f, 0.25f, 0.25f);
    glPushMatrix(); glScalef(0.3f, 0.05f, 0.3f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.3f, 0.0f); glScalef(0.06f, 0.6f, 0.06f); solidCube(1.0f); glPopMatrix();

    if (lampOn) {
        glColor3f(1.0f, 0.95f, 0.7f);
        GLfloat lampShadeGlow[] = { 1.0f, 0.7f, 0.2f, 1.0f }; glMaterialfv(GL_FRONT, GL_EMISSION, lampShadeGlow);
    } else { glColor3f(0.4f, 0.35f, 0.3f); }
    glPushMatrix(); glTranslatef(0.0f, 0.7f, 0.0f); glScalef(0.5f, 0.4f, 0.5f); solidCube(1.0f); glPopMatrix();
    GLfloat killGlow[] = { 0.0f, 0.0f, 0.0f, 1.0f }; glMaterialfv(GL_FRONT, GL_EMISSION, killGlow); glPopMatrix();

    glPushMatrix(); glTranslatef(-0.2f, 0.85f, 0.1f);
    glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glDepthMask(GL_FALSE);
    glColor4f(0.7f, 0.9f, 1.0f, 0.3f); glPushMatrix(); glScalef(0.2f, 0.4f, 0.2f); solidCube(1.0f); glPopMatrix();
    glColor4f(0.1f, 0.5f, 0.9f, 0.7f); glPushMatrix(); glTranslatef(0.0f, -0.05f, 0.0f); glScalef(0.18f, 0.28f, 0.18f); solidCube(1.0f); glPopMatrix();
    glDepthMask(GL_TRUE); glDisable(GL_BLEND); glPopMatrix();
}

void drawSwitchBoard() {
    glColor3f(0.7f, 0.7f, 0.7f); glPushMatrix(); glScalef(0.7f, 0.4f, 0.05f); solidCube(1.0f); glPopMatrix();
    glColor3f(0.9f, 0.9f, 0.9f);
    glPushMatrix(); glTranslatef(-0.2f, 0.0f, 0.03f); glScalef(0.08f, 0.18f, 0.03f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-0.05f, 0.0f, 0.03f); glScalef(0.08f, 0.18f, 0.03f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef( 0.1f, 0.0f, 0.03f); glScalef(0.08f, 0.18f, 0.03f); solidCube(1.0f); glPopMatrix();
    if(projLightOn) glColor3f(1.0f, 0.75f, 0.0f); else glColor3f(0.4f, 0.4f, 0.4f);
    glPushMatrix(); glTranslatef( 0.25f, 0.0f, 0.03f); glScalef(0.08f, 0.18f, 0.03f); solidCube(1.0f); glPopMatrix();
    glColor3f(0.1f, 0.1f, 0.1f);
    glPushMatrix(); glTranslatef(0.4f, 0.0f, 0.03f); GLUquadric *quad = gluNewQuadric(); gluDisk(quad, 0, 0.04, 32, 1); glPopMatrix();
}

void drawCeilingLight() {
    glPushMatrix(); glTranslatef(0.0f, 6.95f, -2.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    glPushMatrix(); glScalef(2.0f, 0.05f, 1.0f); solidCube(1.0f); glPopMatrix();

    if(lightOn) {
        GLfloat glow[] = {1.0f, 1.0f, 1.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, glow); glColor3f(1.0f, 1.0f, 1.0f);
    } else { glColor3f(0.3f, 0.3f, 0.3f); }
    glPushMatrix(); glTranslatef(0.0f, -0.05f, 0.0f); glScalef(1.8f, 0.05f, 0.8f); solidCube(1.0f); glPopMatrix();
    GLfloat noGlow[] = {0.0f, 0.0f, 0.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, noGlow);
    glPopMatrix();
}

void drawSpotlightFixtures() {
    glPushMatrix(); glTranslatef(-4.5f, 6.8f, -1.5f); glColor3f(0.15f, 0.15f, 0.15f);
    glPushMatrix(); glRotatef(45.0f, 0, 0, 1); glScalef(0.4f, 0.3f, 0.3f); solidCube(1.0f); glPopMatrix();
    if(projLightOn) { GLfloat warmGlow[] = { 1.0f, 0.8f, 0.4f, 1.0f }; glMaterialfv(GL_FRONT, GL_EMISSION, warmGlow); glColor3f(1.0f, 0.9f, 0.6f); }
    else { glColor3f(0.2f, 0.2f, 0.2f); }
    glPushMatrix(); glTranslatef(-0.18f, -0.18f, 0.0f); glRotatef(45.0f, 0, 0, 1); glScalef(0.05f, 0.25f, 0.25f); solidCube(1.0f); glPopMatrix();
    GLfloat noGlow[] = {0.0f, 0.0f, 0.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, noGlow); glPopMatrix();

    glPushMatrix(); glTranslatef(-4.5f, 6.8f, 5.0f); glColor3f(0.15f, 0.15f, 0.15f);
    glPushMatrix(); glRotatef(45.0f, 0, 0, 1); glScalef(0.4f, 0.3f, 0.3f); solidCube(1.0f); glPopMatrix();
    if(projLightOn) { GLfloat warmGlow[] = { 1.0f, 0.8f, 0.4f, 1.0f }; glMaterialfv(GL_FRONT, GL_EMISSION, warmGlow); glColor3f(1.0f, 0.9f, 0.6f); }
    else { glColor3f(0.2f, 0.2f, 0.2f); }
    glPushMatrix(); glTranslatef(-0.18f, -0.18f, 0.0f); glRotatef(45.0f, 0, 0, 1); glScalef(0.05f, 0.25f, 0.25f); solidCube(1.0f); glPopMatrix();
    glMaterialfv(GL_FRONT, GL_EMISSION, noGlow); glPopMatrix();

    glColor3f(0.1f, 0.1f, 0.1f);
    glPushMatrix(); glTranslatef(-4.5f, 6.95f, 1.75f); glScalef(0.2f, 0.05f, 7.5f); solidCube(1.0f); glPopMatrix();
}

void drawAC() {
    glPushMatrix(); glTranslatef(7.8f, 5.5f, -4.0f); glRotatef(-90.0f, 0, 1, 0);
    glColor3f(0.85f, 0.85f, 0.85f); glPushMatrix(); glScalef(2.0f, 0.6f, 0.4f); solidCube(1.0f); glPopMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); glPushMatrix(); glTranslatef(0.0f, -0.2f, 0.21f); glScalef(1.8f, 0.1f, 0.05f); solidCube(1.0f); glPopMatrix();
    if(acOn) {
        glColor3f(0.0f, 1.0f, 0.0f); GLfloat ledGlow[] = {0.0f, 1.0f, 0.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, ledGlow);
        glPushMatrix(); glTranslatef(0.8f, -0.1f, 0.21f); glScalef(0.05f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();
        glColor3f(0.0f, 0.8f, 1.0f); GLfloat tempGlow[] = {0.0f, 0.8f, 1.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, tempGlow);
        glPushMatrix(); glTranslatef(0.4f, -0.1f, 0.22f); glScalef(0.0015f, 0.0015f, 1.0f); glLineWidth(2.0f); glutStrokeCharacter(GLUT_STROKE_ROMAN, '2'); glutStrokeCharacter(GLUT_STROKE_ROMAN, '2'); glLineWidth(1.0f); glPopMatrix();
        GLfloat mistGlow[] = {0.8f, 0.9f, 1.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, mistGlow);
        glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glDepthMask(GL_FALSE);
        for(int i = 0; i < 3; i++) {
            float currentOffset = mistOffset + (i * 0.33f); if (currentOffset > 1.0f) currentOffset -= 1.0f;
            float alpha = (1.0f - currentOffset) * 0.4f; glColor4f(0.8f, 0.9f, 1.0f, alpha);
            glPushMatrix(); glTranslatef(0.0f, -0.3f - (currentOffset * 0.8f), 0.2f + (currentOffset * 0.3f)); glScalef(1.5f, 0.05f, 0.2f); solidCube(1.0f); glPopMatrix();
        }
        glDepthMask(GL_TRUE); glDisable(GL_BLEND);
    } else {
        glColor3f(0.1f, 0.1f, 0.1f); glPushMatrix(); glTranslatef(0.8f, -0.1f, 0.21f); glScalef(0.05f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();
    }
    GLfloat noGlow[] = {0.0f, 0.0f, 0.0f, 1.0f}; glMaterialfv(GL_FRONT, GL_EMISSION, noGlow); glPopMatrix();
}

void drawOutdoorAC() {
    glPushMatrix(); glTranslatef(8.6f, 1.0f, -4.0f);
    glColor3f(0.85f, 0.85f, 0.8f); glPushMatrix(); glScalef(0.6f, 1.2f, 1.4f); solidCube(1.0f); glPopMatrix();
    glColor3f(0.1f, 0.1f, 0.1f); glPushMatrix(); glTranslatef(0.31f, 0.0f, 0.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f); GLUquadric *quad = gluNewQuadric(); gluDisk(quad, 0, 0.45, 32, 1); glPopMatrix();
    glPushMatrix(); glTranslatef(0.32f, 0.0f, 0.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f); glRotatef(acFanAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    for(int i = 0; i < 3; i++) { glPushMatrix(); glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f); glTranslatef(0.0f, 0.2f, 0.0f); glScalef(0.08f, 0.4f, 0.02f); solidCube(1.0f); glPopMatrix(); }
    glPopMatrix();
    glColor3f(0.3f, 0.3f, 0.3f);
    glPushMatrix(); glTranslatef(-0.2f, -0.6f,  0.4f); glScalef(0.4f, 0.1f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-0.2f, -0.6f, -0.4f); glScalef(0.4f, 0.1f, 0.1f); solidCube(1.0f); glPopMatrix();
    glPopMatrix();
}

void drawExtraDetails() {
    glColor3f(0.3f, 0.3f, 0.3f); glPushMatrix(); glTranslatef(7.2f, 0.6f, -7.2f); glScalef(0.5f, 1.2f, 0.5f); solidCube(1.0f); glPopMatrix();
    glColor3f(0.05f, 0.05f, 0.05f); glPushMatrix(); glTranslatef(7.2f, 1.21f, -7.2f); glScalef(0.4f, 0.02f, 0.4f); solidCube(1.0f); glPopMatrix();

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, rugTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 0.01f, -1.0f); glScalef(5.0f, 0.01f, 3.5f); solidCube(1.0f); glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void drawPhotoFrames() {
    glPushMatrix(); glTranslatef(-7.9f, 4.5f, -1.5f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glScalef(2.2f, 2.2f, 0.05f); solidCube(1.0f); glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, emonTex); float s = 1.0f;
    glBegin(GL_QUADS); glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-s, -s, 0.03f); glTexCoord2f(1.0f, 0.0f); glVertex3f( s, -s, 0.03f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( s,  s, 0.03f); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s,  s, 0.03f);
    glEnd(); glDisable(GL_TEXTURE_2D); glPopMatrix();

    glPushMatrix(); glTranslatef(-7.9f, 4.5f, 5.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glScalef(2.2f, 2.2f, 0.05f); solidCube(1.0f); glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, ranaTex);
    glBegin(GL_QUADS); glNormal3f(0, 0, 1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-s, -s, 0.03f); glTexCoord2f(1.0f, 0.0f); glVertex3f( s, -s, 0.03f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( s,  s, 0.03f); glTexCoord2f(0.0f, 1.0f); glVertex3f(-s,  s, 0.03f);
    glEnd(); glDisable(GL_TEXTURE_2D); glPopMatrix();
}

void drawDoor() {
    glPushMatrix();
    glTranslatef(1.5f, 0.0f, 8.05f); glRotatef(-doorAngle, 0.0f, 1.0f, 0.0f); glTranslatef(-1.5f, 0.0f, -8.05f);
    glTranslatef(0.0f, 2.5f, 8.05f);

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, doorTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glScalef(3.0f, 5.0f, 0.1f); solidCube(1.0f); glPopMatrix(); glDisable(GL_TEXTURE_2D);

    GLfloat no_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; glMaterialfv(GL_FRONT, GL_SPECULAR, no_specular);
    GLfloat blackPlate[] = { 0.05f, 0.05f, 0.05f, 1.0f }; glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blackPlate);
    glPushMatrix(); glTranslatef(-1.1f, 0.0f, 0.06f); glScalef(0.1f, 0.4f, 0.02f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-1.1f, 0.0f, -0.06f); glScalef(0.1f, 0.4f, 0.02f); solidCube(1.0f); glPopMatrix();

    GLfloat trueGold[] = { 0.85f, 0.7f, 0.2f, 1.0f }; glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, trueGold);
    glPushMatrix(); glTranslatef(-0.95f, 0.0f, 0.08f); glScalef(0.3f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-0.95f, 0.0f, -0.08f); glScalef(0.3f, 0.05f, 0.05f); solidCube(1.0f); glPopMatrix();

    GLfloat standard_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; glMaterialfv(GL_FRONT, GL_SPECULAR, standard_specular);
    glPopMatrix();
}

void drawWindowAndCurtains() {

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE);


    glPushMatrix();
    glTranslatef(-2.0f, 3.5f, -7.9f);
    glRotatef(windowOffset * 90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.0f, 0.0f, 0.0f);
    glColor4f(0.5f, 0.8f, 0.9f, 0.4f);
    glPushMatrix(); glScalef(2.0f, 3.0f, 0.05f); solidCube(1.0f); glPopMatrix();

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 1.45f, 0.0f); glScalef(2.0f, 0.1f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, -1.45f, 0.0f); glScalef(2.0f, 0.1f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-0.95f, 0.0f, 0.0f); glScalef(0.1f, 3.0f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.95f, 0.0f, 0.0f); glScalef(0.1f, 3.0f, 0.06f); solidCube(1.0f); glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2.0f, 3.5f, -7.9f);
    glRotatef(-windowOffset * 90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glColor4f(0.5f, 0.8f, 0.9f, 0.4f);
    glPushMatrix(); glScalef(2.0f, 3.0f, 0.05f); solidCube(1.0f); glPopMatrix();

    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 1.45f, 0.0f); glScalef(2.0f, 0.1f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, -1.45f, 0.0f); glScalef(2.0f, 0.1f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-0.95f, 0.0f, 0.0f); glScalef(0.1f, 3.0f, 0.06f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.95f, 0.0f, 0.0f); glScalef(0.1f, 3.0f, 0.06f); solidCube(1.0f); glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);


    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix(); glTranslatef(0.0f, 5.35f, -7.7f); glScalef(5.0f, 0.08f, 0.08f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(-2.5f, 5.35f, -7.8f); glScalef(0.12f, 0.15f, 0.2f); solidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(2.5f, 5.35f, -7.8f); glScalef(0.12f, 0.15f, 0.2f); solidCube(1.0f); glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, curtainTex);
    glColor3f(1.0f, 1.0f, 1.0f);

    float currentScale = 1.0f - (curtainOffset * 0.75f);


    glPushMatrix();
    glTranslatef(-2.2f, 3.6f, -7.75f);
    glScalef(currentScale, 1.0f, 1.0f);
    glTranslatef(1.1f, 0.0f, 0.0f);
    glScalef(2.2f, 3.4f, 0.05f);
    solidCube(1.0f);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2.2f, 3.6f, -7.75f);
    glScalef(currentScale, 1.0f, 1.0f);
    glTranslatef(-1.1f, 0.0f, 0.0f);
    glScalef(2.2f, 3.4f, 0.05f);
    solidCube(1.0f);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void drawAllFurniture() {
    glPushMatrix(); glTranslatef(6.5f, 0.0f, 0.0f); glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); drawTable(); drawDesktopSetup(); glPopMatrix();
    glPushMatrix(); glTranslatef(4.5f, 0.0f, 0.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f); drawChair(); glPopMatrix();
    glPushMatrix(); glTranslatef(-7.3f, 0.0f, 2.0f); glRotatef(90.0f, 0.0f, 1.0f, 0.0f); drawBookshelf(); glPopMatrix();
    glPushMatrix(); glTranslatef(-5.5f, 0.0f, -4.0f); drawBed(); glPopMatrix();
    glPushMatrix(); glTranslatef(2.5f, 0.0f, -6.5f); drawSofa(); glPopMatrix();
    glPushMatrix(); glTranslatef(-2.5f, 0.75f, -6.5f); drawBedSideTable(); glPopMatrix();
    glPushMatrix(); glTranslatef(7.9f, 4.0f, 1.5f); glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); drawSwitchBoard(); glPopMatrix();

    drawPhotoFrames();
    drawSpotlightFixtures();
    drawDoor();
    drawCeilingLight();
    drawExtraDetails();


    drawWindowAndCurtains();
    drawAC();
    drawOutdoorAC();
}
