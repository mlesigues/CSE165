#ifndef VEC_H
#define VEC_H

#include <iostream>
using namespace std;

class Vec {
private:
	float x;
	float y;

/*public :
		Vec();
		Vec(float u, float v);
		void add(Vec obj1);
		void setX(float x);
		void setY(float y);
		float getX() const;
		float getY() const;
		void print();*/

public: //REARRANGE EVERYTHING, MAYBE THIS WILL WORK!!!
	Vec() {//default constructor ...
		/*float*/ x = 0.0; //maybe change to int??? or maybe float?? not sure tbh
		/*float*/ y = 0.0;
	}

	Vec(float u, float v) { // customize constructor
	        x = u;
	        y = v;
	}
	//add method/function here
	void add (Vec obj1) {
		x += obj1.x;
		y += obj1.y;
	}

	void setX(float x) {
          this->x = x;
  }

  void setY(float y) {
          this->y = y;
  }

  float getX() const { //put const here because of the cpp file!
          return x;
  }

	float getY() const {//put const here because of the cpp file!
          return y;
  }

	//print function here
	void print () {
		cout << "(" << x << ", " << y << ")" << endl;
	}

}; //DO NOT FORGET THIS!!!

#endif
