#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include "furniture.h"
#include "room.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

float cameraX = 0.0f, cameraY = 4.0f, cameraZ = 15.0f;
float roomRotX = 0.0f, roomRotY = 0.0f, roomRotZ = 0.0f;


GLuint floorTex, outWallTex, inWallTex, woodTex, windowTex, pcTex, clockTex, doorTex, sofaTex, bedsheetTex, emonTex, ranaTex, rugTex, keyboardTex, mouseTex, curtainTex;

GLuint loadTextureFile(const char* path) {
    GLuint textureID; glGenTextures(1, &textureID); glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels; stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data); stbi_image_free(data);
    } else { printf("Failed to load texture: %s\n", path); }
    return textureID;
}

void drawFloor() {
    glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, floorTex); glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-12.0f, 0.0f, -12.0f); glTexCoord2f(6, 0); glVertex3f( 12.0f, 0.0f, -12.0f);
    glTexCoord2f(6, 6); glVertex3f( 12.0f, 0.0f,  20.0f); glTexCoord2f(0, 6); glVertex3f(-12.0f, 0.0f,  20.0f);
    glEnd(); glDisable(GL_TEXTURE_2D);
}

void drawCeiling() {
    glColor3f(0.95f, 0.95f, 0.95f);
    glBegin(GL_QUADS); glVertex3f(-8.0f, 7.0f, -8.0f); glVertex3f( 8.0f, 7.0f, -8.0f); glVertex3f( 8.0f, 7.0f,  8.0f); glVertex3f(-8.0f, 7.0f,  8.0f); glEnd();
}

void drawWalls() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, inWallTex); glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0); glVertex3f(-8.0f, 0.0f, -8.0f); glTexCoord2f(2, 0); glVertex3f( 8.0f, 0.0f, -8.0f);
    glTexCoord2f(2, 0.3f); glVertex3f( 8.0f, 2.0f, -8.0f); glTexCoord2f(0, 0.3f); glVertex3f(-8.0f, 2.0f, -8.0f);
    glTexCoord2f(0, 0.7f); glVertex3f(-8.0f, 5.0f, -8.0f); glTexCoord2f(2, 0.7f); glVertex3f( 8.0f, 5.0f, -8.0f);
    glTexCoord2f(2, 1.0f); glVertex3f( 8.0f, 7.0f, -8.0f); glTexCoord2f(0, 1.0f); glVertex3f(-8.0f, 7.0f, -8.0f);
    glTexCoord2f(0, 0.3f); glVertex3f(-8.0f, 2.0f, -8.0f); glTexCoord2f(0.37f, 0.3f); glVertex3f(-2.0f, 2.0f, -8.0f);
    glTexCoord2f(0.37f, 0.7f); glVertex3f(-2.0f, 5.0f, -8.0f); glTexCoord2f(0, 0.7f); glVertex3f(-8.0f, 5.0f, -8.0f);
    glTexCoord2f(0.62f, 0.3f); glVertex3f( 2.0f, 2.0f, -8.0f); glTexCoord2f(2, 0.3f); glVertex3f( 8.0f, 2.0f, -8.0f);
    glTexCoord2f(2, 0.7f); glVertex3f( 8.0f, 5.0f, -8.0f); glTexCoord2f(0.62f, 0.7f); glVertex3f( 2.0f, 5.0f, -8.0f);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(-8.0f, 0.0f,  8.0f); glTexCoord2f(2, 0); glVertex3f(-8.0f, 0.0f, -8.0f);
    glTexCoord2f(2, 1); glVertex3f(-8.0f, 7.0f, -8.0f); glTexCoord2f(0, 1); glVertex3f(-8.0f, 7.0f,  8.0f);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(8.0f, 0.0f, -8.0f); glTexCoord2f(2, 0); glVertex3f(8.0f, 0.0f,  8.0f);
    glTexCoord2f(2, 1); glVertex3f(8.0f, 7.0f,  8.0f); glTexCoord2f(0, 1); glVertex3f(8.0f, 7.0f, -8.0f);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0); glVertex3f(-8.0f, 0.0f, 8.0f); glTexCoord2f(2, 0); glVertex3f(-1.5f, 0.0f, 8.0f);
    glTexCoord2f(2, 1); glVertex3f(-1.5f, 7.0f, 8.0f); glTexCoord2f(0, 1); glVertex3f(-8.0f, 7.0f, 8.0f);
    glTexCoord2f(0, 0); glVertex3f( 1.5f, 0.0f, 8.0f); glTexCoord2f(2, 0); glVertex3f( 8.0f, 0.0f, 8.0f);
    glTexCoord2f(2, 1); glVertex3f( 8.0f, 7.0f, 8.0f); glTexCoord2f(0, 1); glVertex3f( 1.5f, 7.0f, 8.0f);
    glTexCoord2f(0, 0.7f); glVertex3f(-1.5f, 5.0f, 8.0f); glTexCoord2f(1, 0.7f); glVertex3f( 1.5f, 5.0f, 8.0f);
    glTexCoord2f(1, 1.0f); glVertex3f( 1.5f, 7.0f, 8.0f); glTexCoord2f(0, 1.0f); glVertex3f(-1.5f, 7.0f, 8.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, outWallTex);
    glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0); glVertex3f( 8.0f, 0.0f, -8.1f); glTexCoord2f(4, 0); glVertex3f(-8.0f, 0.0f, -8.1f);
    glTexCoord2f(4, 0.3f); glVertex3f(-8.0f, 2.0f, -8.1f); glTexCoord2f(0, 0.3f); glVertex3f( 8.0f, 2.0f, -8.1f);
    glTexCoord2f(0, 0.7f); glVertex3f( 8.0f, 5.0f, -8.1f); glTexCoord2f(4, 0.7f); glVertex3f(-8.0f, 5.0f, -8.1f);
    glTexCoord2f(4, 1.0f); glVertex3f(-8.0f, 7.0f, -8.1f); glTexCoord2f(0, 1.0f); glVertex3f( 8.0f, 7.0f, -8.1f);
    glTexCoord2f(0, 0.3f); glVertex3f( 8.0f, 2.0f, -8.1f); glTexCoord2f(0.37f, 0.3f); glVertex3f( 2.0f, 2.0f, -8.1f);
    glTexCoord2f(0.37f, 0.7f); glVertex3f( 2.0f, 5.0f, -8.1f); glTexCoord2f(0, 0.7f); glVertex3f( 8.0f, 5.0f, -8.1f);
    glTexCoord2f(0.62f, 0.3f); glVertex3f(-2.0f, 2.0f, -8.1f); glTexCoord2f(4, 0.3f); glVertex3f(-8.0f, 2.0f, -8.1f);
    glTexCoord2f(4, 0.7f); glVertex3f(-8.0f, 5.0f, -8.1f); glTexCoord2f(0.62f, 0.7f); glVertex3f(-2.0f, 5.0f, -8.1f);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(-8.1f, 0.0f, -8.0f); glTexCoord2f(4, 0); glVertex3f(-8.1f, 0.0f,  8.0f);
    glTexCoord2f(4, 2); glVertex3f(-8.1f, 7.0f,  8.0f); glTexCoord2f(0, 2); glVertex3f(-8.1f, 7.0f, -8.0f);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(8.1f, 0.0f,  8.0f); glTexCoord2f(4, 0); glVertex3f(8.1f, 0.0f, -8.0f);
    glTexCoord2f(4, 2); glVertex3f(8.1f, 7.0f, -8.0f); glTexCoord2f(0, 2); glVertex3f(8.1f, 7.0f,  8.0f);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0); glVertex3f(-8.0f, 0.0f, 8.1f); glTexCoord2f(2, 0); glVertex3f(-1.5f, 0.0f, 8.1f);
    glTexCoord2f(2, 1); glVertex3f(-1.5f, 7.0f, 8.1f); glTexCoord2f(0, 1); glVertex3f(-8.0f, 7.0f, 8.1f);
    glTexCoord2f(0, 0); glVertex3f( 1.5f, 0.0f, 8.1f); glTexCoord2f(2, 0); glVertex3f( 8.0f, 0.0f, 8.1f);
    glTexCoord2f(2, 1); glVertex3f( 8.0f, 7.0f, 8.1f); glTexCoord2f(0, 1); glVertex3f( 1.5f, 7.0f, 8.1f);
    glTexCoord2f(0, 0.7f); glVertex3f(-1.5f, 5.0f, 8.1f); glTexCoord2f(1, 0.7f); glVertex3f( 1.5f, 5.0f, 8.1f);
    glTexCoord2f(1, 1.0f); glVertex3f( 1.5f, 7.0f, 8.1f); glTexCoord2f(0, 1.0f); glVertex3f(-1.5f, 7.0f, 8.1f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, woodTex); glColor3f(1.0f, 1.0f, 1.0f);
    float outZ = 8.12f, inZ = 7.98f, midZOut = 8.1f, midZIn = 8.0f;
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(-1.7f, 0.0f, outZ); glTexCoord2f(1,0); glVertex3f(-1.5f, 0.0f, outZ);
    glTexCoord2f(1,2); glVertex3f(-1.5f, 5.2f, outZ); glTexCoord2f(0,2); glVertex3f(-1.7f, 5.2f, outZ);
    glTexCoord2f(0,0); glVertex3f(1.5f, 0.0f, outZ); glTexCoord2f(1,0); glVertex3f(1.7f, 0.0f, outZ);
    glTexCoord2f(1,2); glVertex3f(1.7f, 5.2f, outZ); glTexCoord2f(0,2); glVertex3f(1.5f, 5.2f, outZ);
    glTexCoord2f(0,0); glVertex3f(-1.7f, 5.0f, outZ); glTexCoord2f(2,0); glVertex3f(1.7f, 5.0f, outZ);
    glTexCoord2f(2,0.2); glVertex3f(1.7f, 5.2f, outZ); glTexCoord2f(0,0.2); glVertex3f(-1.7f, 5.2f, outZ);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0,0); glVertex3f(-1.5f, 0.0f, inZ); glTexCoord2f(1,0); glVertex3f(-1.7f, 0.0f, inZ);
    glTexCoord2f(1,2); glVertex3f(-1.7f, 5.2f, inZ); glTexCoord2f(0,2); glVertex3f(-1.5f, 5.2f, inZ);
    glTexCoord2f(0,0); glVertex3f(1.7f, 0.0f, inZ); glTexCoord2f(1,0); glVertex3f(1.5f, 0.0f, inZ);
    glTexCoord2f(1,2); glVertex3f(1.5f, 5.2f, inZ); glTexCoord2f(0,2); glVertex3f(1.7f, 5.2f, inZ);
    glTexCoord2f(0,0); glVertex3f(1.7f, 5.0f, inZ); glTexCoord2f(2,0); glVertex3f(-1.7f, 5.0f, inZ);
    glTexCoord2f(2,0.2); glVertex3f(-1.7f, 5.2f, inZ); glTexCoord2f(0,0.2); glVertex3f(1.7f, 5.2f, inZ);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-1.5f, 0.0f, midZIn); glTexCoord2f(1,0); glVertex3f(-1.5f, 0.0f, midZOut);
    glTexCoord2f(1,2); glVertex3f(-1.5f, 5.0f, midZOut); glTexCoord2f(0,2); glVertex3f(-1.5f, 5.0f, midZIn);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(1.5f, 0.0f, midZOut); glTexCoord2f(1,0); glVertex3f(1.5f, 0.0f, midZIn);
    glTexCoord2f(1,2); glVertex3f(1.5f, 5.0f, midZIn); glTexCoord2f(0,2); glVertex3f(1.5f, 5.0f, midZOut);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0,0); glVertex3f(-1.5f, 5.0f, midZIn); glTexCoord2f(2,0); glVertex3f(1.5f, 5.0f, midZIn);
    glTexCoord2f(2,1); glVertex3f(1.5f, 5.0f, midZOut); glTexCoord2f(0,1); glVertex3f(-1.5f, 5.0f, midZOut);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawSky() {
    glDisable(GL_LIGHTING); glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, windowTex); glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0); glVertex3f(-10.0f, -2.0f, -12.0f); glTexCoord2f(1, 0); glVertex3f( 10.0f, -2.0f, -12.0f);
    glTexCoord2f(1, 1); glVertex3f( 10.0f, 10.0f, -12.0f); glTexCoord2f(0, 1); glVertex3f(-10.0f, 10.0f, -12.0f);
    glEnd(); glDisable(GL_TEXTURE_2D); glEnable(GL_LIGHTING);
}

void drawRoom() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, cameraY, cameraZ, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(roomRotX, 1.0f, 0.0f, 0.0f);
    glRotatef(roomRotY, 0.0f, 1.0f, 0.0f);
    glRotatef(roomRotZ, 0.0f, 0.0f, 1.0f);

    glEnable(GL_LIGHTING);

    if (lightOn) {
        glEnable(GL_LIGHT0);
        GLfloat pos0[] = { 0.0f, 6.8f, -2.0f, 1.0f };
        glLightfv(GL_LIGHT0, GL_POSITION, pos0);
    } else {
        glDisable(GL_LIGHT0);
    }

    if (projLightOn) {
        glEnable(GL_LIGHT1); glEnable(GL_LIGHT2);
        GLfloat spot1_pos[] = { -4.5f, 6.8f, -1.5f, 1.0f };
        GLfloat spot_dir[]  = { -1.0f, -0.6f, 0.0f };
        glLightfv(GL_LIGHT1, GL_POSITION, spot1_pos);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_dir);
        GLfloat spot2_pos[] = { -4.5f, 6.8f, 5.0f, 1.0f };
        glLightfv(GL_LIGHT2, GL_POSITION, spot2_pos);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_dir);
    } else {
        glDisable(GL_LIGHT1); glDisable(GL_LIGHT2);
    }

    if (lampOn) {
        glEnable(GL_LIGHT3);
        GLfloat lamp_pos[] = { -2.5f, 1.4f, -6.5f, 1.0f };
        glLightfv(GL_LIGHT3, GL_POSITION, lamp_pos);
    } else {
        glDisable(GL_LIGHT3);
    }

    drawSky(); drawFloor(); drawCeiling(); drawWalls();
    drawAllFurniture();
}

void reshapeRoom(int w, int h) {
    if(h == 0) h = 1;
    glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 1.0, 100.0); glMatrixMode(GL_MODELVIEW);
}

void initRoom() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

     floorTex    = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\floor.png");
    inWallTex   = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\bedroom wall.jpg");
    outWallTex  = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\out wall.jpg");
    woodTex     = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\furniture wood.jpg");
    windowTex   = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\outside window.jpg");
    pcTex       = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\pc.png");
    clockTex    = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\CLOCK.png");
    doorTex     = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\door.png");
    sofaTex     = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\sofacover.jpg");
    bedsheetTex = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\bedsheet.jpg");
    emonTex     = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\team.jpg");
    ranaTex     = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\team 1.jpg");
    rugTex      = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\rug.jpg");


    keyboardTex = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\keyboard.png");
    mouseTex    = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\mouse.png");
    curtainTex  = loadTextureFile("C:\\Users\\nazru\\OneDrive\\Desktop\\C Program\\Glut Project\\3d room\\curtain.jpg");


    glEnable(GL_LIGHTING);

    GLfloat slightly_dark[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, slightly_dark);

    GLfloat white_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat white_amb[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, white_amb);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);

    GLfloat warm_spot[] = { 1.0f, 0.8f, 0.4f, 1.0f };
    GLfloat zero_amb[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, warm_spot); glLightfv(GL_LIGHT1, GL_AMBIENT, zero_amb);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40.0f); glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 15.0f); glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.01f);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, warm_spot); glLightfv(GL_LIGHT2, GL_AMBIENT, zero_amb);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 40.0f); glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 15.0f); glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.01f);

    GLfloat dim_warm[] = { 0.8f, 0.6f, 0.2f, 1.0f };
    GLfloat lamp_amb[] = { 0.1f, 0.1f, 0.05f, 1.0f };
    glLightfv(GL_LIGHT3, GL_DIFFUSE, dim_warm); glLightfv(GL_LIGHT3, GL_AMBIENT, lamp_amb);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0f); glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.2f); glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.05f);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
