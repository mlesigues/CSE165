#include "App.h"
#include "Rect.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(0.0, 0.0, 0.0);
    
    // Draw some rectangles
    glBegin(GL_POLYGON);
    glColor3d(0.431, 1, 0.121);
    glVertex2f(-0.5, -0.4);
    glVertex2f(0.5, -0.4);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    
    glColor3d(0.533, 0.662, 0.905);
    glBegin(GL_POLYGON);
    
    glVertex2f(0.0, -0.6);
    glVertex2f(0.7, -0.6);
    glVertex2f(0.7, 0.0);
    glVertex2f(0.0, 0.0);
    
    glEnd();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Rect* r0 = new Rect(-0.5, 0.5, 0.0, 0.9); // first rect
    Rect* r1 = new Rect(0.0, 0.0, 0.7, 0.6); // second rect
 
    if ((r1->contains(mx, my) == true)) {
        // white 1st rect, red 2nd rect
        glColor3d(0.419, 1, 0.984);
        glBegin(GL_POLYGON);
        glVertex2f(0.0, -0.6);
        glVertex2f(0.7, -0.6);
        glVertex2f(0.7, 0.0);
        glVertex2f(0.0, 0.0);
        glEnd();
        glColor3d(0.533, 0.662, 0.905);
        glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.4);
        glVertex2f(0.5, -0.4);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glEnd();
    }
    else if ((r0->contains(mx, my) == true)) {
        //default pic: red 1st rect, white 2nd rect
        glColor3d(0.419, 1, 0.984);
        glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.4);
        glVertex2f(0.5, -0.4);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glEnd();
        glColor3d(0.533, 0.662, 0.905);
        glBegin(GL_POLYGON);
        glVertex2f(0.0, -0.6);
        glVertex2f(0.7, -0.6);
        glVertex2f(0.7, 0.0);
        glVertex2f(0.0, 0.0);
        glEnd();
    //}
    }
    else if ((r0->contains(mx, my) == false) && (r1->contains(mx, my) == false)) {
        // both white rectangles
        glColor3d(0.419, 1, 0.984);
        glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.4);
        glVertex2f(0.5, -0.4);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glEnd();
        glColor3d(0.533, 0.662, 0.905);
        glBegin(GL_POLYGON);
        glVertex2f(0.0, -0.6);
        glVertex2f(0.7, -0.6);
        glVertex2f(0.7, 0.0);
        glVertex2f(0.0, 0.0);
        glEnd();
    }
    
    glFlush();
    glutSwapBuffers();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}

