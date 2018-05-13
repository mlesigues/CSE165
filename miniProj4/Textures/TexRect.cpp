#include "TexRect.h"


TexRect::TexRect (const char* filename,const char* filename2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    RgbImage theTexMap( filename );//do it again for the second bmp

    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );

    RgbImage theTexMap2( filename2 );

    glGenTextures( 1, &texture_id2 );
    glBindTexture( GL_TEXTURE_2D, texture_id2 );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap2.GetNumCols(), theTexMap2.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData() );

    this->texture_id = texture_id;

    this->rows = rows;
    this->cols = cols;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    curr_row = 0;
    curr_col = 0;

    complete = false;
}

bool TexRect::done() {
    return complete;
}


void TexRect::draw(){

    if(curr_row != 0 && curr_col !=0){ //checks if it explosion or mushroom

    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    //reads the whole explosion sequence
    float xinc = 1.0/cols;
    float yinc = 1.0/rows;


    float top = 1 - yinc * (curr_row - 1);
    float bottom = 1 - yinc * curr_row;

    float left = xinc * (curr_col - 1);
    float right = xinc * curr_col;


    glBegin(GL_QUADS);

    glTexCoord2f(left, bottom);
    glVertex2f(x, y - h);

    glTexCoord2f(left, top);
    glVertex2f(x, y);

    glTexCoord2f(right, top);
    glVertex2f(x+w, y);

    glTexCoord2f(right, bottom);
    glVertex2f(x+w, y - h);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    }

    if(curr_row == 0 && curr_col == 0){ // this is the mushroom
    glBindTexture( GL_TEXTURE_2D, texture_id2 );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex2f(x, y-h);

    glTexCoord2f(0, 1);
    glVertex2f(x, y);

    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);

    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    }
}

void TexRect::incY(){
    y+=0.01;
}

void TexRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }

    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}
bool TexRect::contains(float mx,float my){ //this will trigger the explosion
    if(x <= mx && x <= w+x && y >= my && y >= y-h){
        return true;
    }
       return false;

}

void TexRect::reset(){
    complete = false;
    curr_row = 0;
    curr_col = 0;
}
