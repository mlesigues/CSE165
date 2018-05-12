#include "TicTacToe.h"
#include <iostream>
# include <ctime>
#include <time.h>
using namespace std;
//Default Constructor
TicTacToe::TicTacToe() {
    gameStart = false;
    gameEnd   = false;
    gameResult = Undetermined;
    typeOfGame  = U;
    clicks  = 0;
    win1 = -1;
    win2 = -1;
    win3 = -1;
    cornerOne  = -1;
    cornerTwo = -1;
}

//Setters
void TicTacToe::setGameStart() {
    gameStart = !gameStart;
}

void TicTacToe::setGameType(gameType type) {
    typeOfGame = type;
}

//Getters
bool TicTacToe::getGameStarting() {
  return gameStart;
}
bool TicTacToe::getGameEnding() {
  return gameEnd;
}
shape TicTacToe::getGameResult() {
  return gameResult;
}
gameType TicTacToe::geTypeOfGame() {
  return typeOfGame;
}
int TicTacToe::getWin1() {
  return win1;
}
int TicTacToe::getWin2() {
  return win2;
}
int TicTacToe::getWin3() {
  return win3;
}
shape TicTacToe::playerTurn() {
    //P1 is assign to X
    switch(clicks % 2)
    {
        case 0:
            return O;
        case 1:
            return X;
    }
    return Undetermined;

}

//checkers of the winning patterns
void TicTacToe::CheckBoard(vector<Square*> &grid) {
    //First, second, third Rows
    CheckColRow(0, 2, 1, grid);
    CheckColRow(3, 5, 1, grid);
    CheckColRow(6, 8, 1, grid);

    //First, second, third Column
    CheckColRow(0, 6, 3, grid);
    CheckColRow(1, 4, 3, grid);
    CheckColRow(2, 8, 3, grid);

    // Diagonals
    CheckColRow(0, 8, 4, grid);
    CheckColRow(2, 6, 2, grid);


    //this is will check if it is a draw or not
    if((clicks == 9) && (gameResult == Undetermined))
    {
        gameEnd = true;

    }
}

void TicTacToe::CheckColRow(int start, int end, int off, vector<Square*> &grid) {
    int XCount = 0;
    int OCount = 0;

    //combination of X and O
    for(int i = start; i <= end; i += off)
    {
        if(grid[i]->getShapeType() == X)
            XCount++;
        else if(grid[i]->getShapeType() == O)
            OCount++;
    }

    //who won?
    if(OCount == 3) {
        //P2 lose
        gameResult = O;
        gameEnd = true;

        win1 = start;
        win2 = start + off;
        win3 = end;
    }
    else if(XCount == 3) {
        //P1 won
        gameResult = X;
        gameEnd = true;

        win1 = start;
        win2 = start + off;
        win3 = end;
    }

}

//check moves of human player/P1 player
bool TicTacToe::POneturn(int index, vector<Square*> &grid) {
    //make sure that move is valid
    if(grid[index]->getShapeType() != Undetermined)
        return false;
    clicks++;
    grid[index]->setShape(playerTurn());
    switch(clicks % 2) {
        case 0:
            grid[index]->setColors(1.0f, 0.43f, 0.78f);
            break;
        case 1:
             grid[index]->setColors(0.0f, 1.0f, 0.0f);
    }

    CheckBoard(grid);

    //Valid move
    return true;
}

//PC moves
bool TicTacToe::ComputerCheckBoard(vector<Square*> &grid) {
    //Check First, second, third Row
    if(CheckXO(0, 2, 1, grid))
        return true;
    else if(CheckXO(3, 5, 1, grid))
        return true;
    else if(CheckXO(6, 8, 1, grid))
        return true;
    //Check First, second, third Column
    else if(CheckXO(0, 6, 3, grid))
        return true;
    else if(CheckXO(1, 4, 3, grid))
        return true;
    else if(CheckXO(2, 8, 3, grid))
        return true;
    //Check Diagonals
    else if(CheckXO(0, 8, 4, grid))
        return true;
    else if(CheckXO(2, 6, 2, grid))
        return true;

    return false;
}

bool TicTacToe::CheckXO(int start, int end, int off, vector<Square*> &grid) {
    int XCount = 0;
    int OCount = 0;
    int totalCount = 0;
    int win = -1;

    //how many times did X and O occurred?
    for(int i = start; i <= end; i += off) {
        if(grid[i]->getShapeType() == X) {
            XCount++;
            totalCount++;
        }
        else if(grid[i]->getShapeType() == O) {
            OCount++;
            totalCount++;
        }
        else {
            win = i;
          }
    }

    if(((XCount == 2) || (OCount == 2)) && (totalCount < 3) && (win != -1)) {
        cout << "X count: " << XCount << endl;
        cout << "O Count: " << OCount << endl;
        grid[win]->setShape(X);
        //PC turn
        grid[win]->setColors(1.0, 1.0, 0.0);
        return true;
    }

    //PC did not move
    return false;
}

//PC/AI, my friend and I worked on this part together with combination of (a lot) google searching
void TicTacToe::PCturn(vector<Square*> &grid) { //this is hard btw
    clicks++;
    if(ComputerCheckBoard(grid)) {
        CheckBoard(grid);
        return;
    }
    //Corners: PC will move in corners
    //PC is always black
    //PC First Move
    if(clicks == 1) {
        int corners[4] = {0,2,6,8};
        int time = clock();
        srand(time);
        cornerOne = corners[rand() % 4];
        grid[cornerOne]->setShape(X);
        grid[cornerOne]->setColors(1.0, 1.0, 0.0);
    }
    // Second Move
    else if(clicks == 3) {
        if(grid[4]->getShapeType() != O) {
            switch(cornerOne) {
                case 0:
                    if((grid[3]->getShapeType() != O) && (grid[6]->getShapeType() != O)) {
                        cornerTwo = 6;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    else {
                        cornerTwo = 2;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    //stop
                    break;

                case 2:
                    if((grid[5]->getShapeType() != O) && (grid[8]->getShapeType() != O)) {
                        cornerTwo = 8;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    else {
                        cornerTwo = 0;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    //stop
                    break;

                case 6:
                    if((grid[3]->getShapeType() != O) && (grid[0]->getShapeType() != O)) {
                        cornerTwo = 0;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    else {
                        cornerTwo = 8;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    //stop
                    break;

                case 8:
                    if((grid[5]->getShapeType() != O) && (grid[2]->getShapeType() != O)) {
                        cornerTwo = 2;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    else {
                        cornerTwo = 6;
                        grid[cornerTwo]->setShape(X);
                        grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    }
                    //stop
                    break;
            }
        }
        //if human decide to start in middle of board
        else {
            switch(cornerOne) {

                case 0:
                    cornerTwo = 8;
                    grid[cornerTwo]->setShape(X);
                    grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    break;
                case 2:
                    cornerTwo = 6;
                    grid[cornerTwo]->setShape(X);
                    grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    break;
                case 6:
                    cornerTwo = 2;
                    grid[cornerTwo]->setShape(X);
                    grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    break;
                case 8:
                    cornerTwo = 0;
                    grid[cornerTwo]->setShape(X);
                    grid[cornerTwo]->setColors(1.0, 1.0, 0.0);
                    break;
            }
        }
    }

    //PC Third Move
    else if(clicks == 5) {
        //Special Cases
        if((((cornerOne == 0) || (cornerOne == 6)) && ((cornerTwo == 6)||(cornerTwo == 0))) && (grid[5]->getShapeType() == O)) {
            grid[4]->setShape(X);
            grid[4]->setColors(1.0, 1.0, 0.0);
            return;
        }
        else if((((cornerOne == 2) || (cornerOne == 8)) && ((cornerTwo == 8)||(cornerTwo == 2))) && (grid[3]->getShapeType() == O)) {
            grid[4]->setShape(X);
            grid[4]->setColors(1.0, 1.0, 0.0);
            return;
        }
    }
    CheckBoard(grid);
}
