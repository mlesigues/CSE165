#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
    GLuint texture_id;
    GLuint texture_id2;
    float x;
    float y;
    float w;
    float h;

    int rows;
    int cols;

    int curr_row;
    int curr_col;

    bool complete;
public:
    TexRect (const char*,const char*, int, int, float, float, float, float); //added 1 more char*

    bool done();

    void draw();

    void advance();

    void incY();

    void reset();

    bool contains(float mx, float my);
};

#endif
