#include "App.h"
using namespace std;
#include <iostream>
App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    gridInit();
}

void App::draw() {
//start game
    if(!game.getGameStarting())
        MenuScreen();
    else
    {
        GameInterface();
    }

}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

  //is the box clicked? do it during game
    if((!game.getGameEnding()) && (game.getGameStarting() == true)) {
        int foundIndex;
        for(int  i = 0; i < grid.size(); i++) {
            if(grid[i]->contains(mx, my)) {
                foundIndex = i;
                break;
            }
        }
      //human turn and check if it is PC's turn next
        if(game.POneturn(foundIndex, grid) && (game.geTypeOfGame() == HC)) {
            //PC turn
            game.PCturn(grid);
        }
    }
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y) {
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
    //if the game is have not started, we can still press on keyboard
    if(!game.getGameStarting()) {
        //1 v 1
        if((key == 'h') || (key == 'H')) {
            game.setGameStart();
            game.setGameType(HH);
        }
        //1 vs PC
        else if((key == 'c')||(key == 'C')) {
            game.setGameStart();
            game.setGameType(HC);
            //PC moves first
            game.PCturn(grid);
        }
        redraw();
    }
}

void App::standby() {
    //is it done? who won?
    if((game.getGameEnding() == true) && (game.getGameResult() != U )) {
        grid[game.getWin1()]->setColors(0.0f, 0.0f, 0.0f);
        grid[game.getWin2()]->setColors(0.0f, 0.0f, 0.0f);
        grid[game.getWin3()]->setColors(0.0f, 0.0f, 0.0f);
    }

    //if it is draw, everything will change colors to signify
    else if(game.getGameEnding() && (game.getGameResult() == Undetermined )) {
        for (int i = 0; i < grid.size(); i++) {
            grid[i]->setColors(0.294f, 0.000f, 0.510f);
        }
    }
}

void App::gridInit() {
  //we draw boxes here, total of 9 boxes
   //top first
   //left, middle, center
    Square *square1 = new Square(-1.0f, 1.0f);
    grid.push_back(square1);
    Square *square2 = new Square(-0.333f, 1.0f);
    grid.push_back(square2);
    Square *square3 = new Square(0.333f, 1.0f);
    grid.push_back(square3);

    //middle
  //left, middle, right
    Square *square4 = new Square(-1.0f, 0.333f);
    grid.push_back(square4);
    Square *square5 = new Square(-0.333f, 0.333f);
    grid.push_back(square5);
    Square *square6 = new Square(0.333f,  0.333f);
    grid.push_back(square6);

    //bottom
  //left, middle, right
    Square *square7 = new Square(-1.0f, -0.333f);
    grid.push_back(square7);
    Square *square8 = new Square(-0.333f, -0.333f);
    grid.push_back(square8);
    Square *square9 = new Square(0.333f, -0.333f);
    grid.push_back(square9);

}

void App::MenuScreen() {
  // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Set background color to (not) black
    glClearColor(1.0, 1.0, 1.0, 1.0);

// Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


//this loads the menu, with text
    glRasterPos2f(-0.85f, 0.1f);
    glColor3f(1.0f, 0.0f, 0.0f);
    string message1 = "WELCOME TO TICTACTOE";
    string message4 = "SELECT ONE:";
    string message2 = "1 vs 1: H";
    string message3 = "1 vs PC: C";

//display the message on the menu
  glRasterPos2f(-0.5f, 0.0f);
  for(int i = 0; i < message1.length(); i++)
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message1[i]);

  glRasterPos2f(-0.5f, -0.1f);
  for(int i = 0; i < message4.length(); i++)
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, message4[i]);

//position  the text, eyeballing it
  glRasterPos2f(-0.5f, -0.2f);
  for(int i = 0; i < message2.length(); i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, message2[i]);
  glRasterPos2f(-0.5f, -0.3f);
  for(int i = 0; i < message3.length(); i++)
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15, message3[i]);
  glFlush();
  glutSwapBuffers();
}


void App :: GameInterface() {
  // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 // Set background color to (not)black
    glClearColor(1.0, 1.0, 1.0, 1.0);
 // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //drawing the lines here
    glColor3f(1.0f, 0.0f, 0.0f); //red color
    glLineWidth(20.0f); //dis new, basically thickens the line ;)
    glBegin(GL_LINES);

    //Horizontal Lines
    glVertex2f(-1.0f, 0.333f);
    glVertex2f(1.0f, 0.333f);
    glVertex2f(-1.0f, -0.333f);
    glVertex2f(1.0f, -0.333f);

    //Vertical Lines
    glVertex2f(-0.333f, 1.0f);
    glVertex2f(-0.333f, -1.0f);
    glVertex2f(0.333f, 1.0f);
    glVertex2f(0.333f, -1.0f);

    glEnd();

    //Draw X and O
    for (int i = 0; i < grid.size(); i++) {
      //we color the X something different
        glColor3f(grid[i]->getBlue(), grid[i]->getBlue(), grid[i]->getBlue());

        //Draw X
        if(grid[i]->getShapeType() == X) {
            glBegin(GL_QUADS); //because polygon is hard for me
            //first leg of x
            glVertex2f(grid[i]->getXcent() - 0.2, grid[i]->getYcent() + 0.1);
            glVertex2f(grid[i]->getXcent() - 0.1, grid[i]->getYcent() + 0.2);
            glVertex2f(grid[i]->getXcent() + 0.2, grid[i]->getYcent() - 0.1);
            glVertex2f(grid[i]->getXcent() + 0.1, grid[i]->getYcent() - 0.2);
            //second leg of x
            glVertex2f(grid[i]->getXcent() + 0.2, grid[i]->getYcent() + 0.1);
            glVertex2f(grid[i]->getXcent() + 0.1, grid[i]->getYcent() + 0.2);
            glVertex2f(grid[i]->getXcent() - 0.2, grid[i]->getYcent() - 0.1);
            glVertex2f(grid[i]->getXcent() - 0.1, grid[i]->getYcent() - 0.2);

            glEnd();
            redraw();
        }

        //Draw O, like the previous lab
        else if (grid[i] -> getShapeType() == O) {
          //smaller circle
            int vertice = 1000; //smoother
            float rad   = 0.1f;
            float fullCircle = M_PI * 2;

            //smaller circle, it is not black
            glColor3f(1.0f, 1.0f, 1.0f);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(grid[i]->getXcent(), grid[i]->getYcent());

            for(int j = 0; j <= vertice; j++) {
                glVertex2f(grid[i]->getXcent()+rad*cosf(j*fullCircle/vertice), grid[i]->getYcent()+rad*sinf(j*fullCircle/vertice));
            }
            glEnd();
            redraw();

            //Outer Circle
            rad = 0.2f;
            glColor3f(grid[i]->getBlue(), grid[i]->getBlue(), grid[i]->getRed());
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(grid[i]->getXcent(), grid[i]->getYcent());

            //this is like the previous lab, using sin and cos to get a circle
            for(int j = 0; j <= vertice; j++) {
                glVertex2f(grid[i]->getXcent()+rad*cosf(j*fullCircle/vertice), grid[i]->getYcent()+rad*sinf(j*fullCircle/vertice));
            }
            glEnd();
            redraw();
        }
    }
    glFlush();
    glutSwapBuffers();
}
