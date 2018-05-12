#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rect.h" //don't do "_"
#include <vector> //duhhhh???!!!
//#include "Vec_h"
using namespace std; //hehehe, don't forget this
class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;

public:
	// Constructor, to initialize state
	App(const char* label, int x, int y, int w, int h);
    

	// These are the events we want to handle
	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);
	//vector<ssomethingsomething>
	//vector<Rect*>rectPointer; //is this the Rect pointer???? hmmm
	//need destructors: ~somethinghere()
	/*~App() {
		for(int i = 0; i < rectPointer.size(); i++) {//a list of Rect pointers, mmmm
			Rect* ptr = rectPointer[i];
			delete ptr;
		}
	}*/
/*
	bool Rect::contains(float x, float y) {//method called contains btw
		if(upperLeftx <= x && (upperLeftx + widthRect) >= x && upperLefty >= y && (upperLefty - heightRect) <= y) {
			return true;
		}
                else
                        return false;
	}*/

};

#endif
