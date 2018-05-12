#ifndef Circle_h
#define Circle_h
#include <iostream>
#include <vector>
#include <algorithm>
//#include "Data.h"
#include "Sortable.h"
using namespace std;

class Circle:public Sortable { //inherits from Sortable (extend Sortable)
//only radius, printed one line: Circle with radius x (x = radius)
  float radius; //float or int ?
public:
  Circle() { //constructor
   //radius = 0;
  }

  Circle (float radius) {
    this->radius = radius;
  }

  //get the boolean on Sortable
  virtual bool compare (const Sortable * s) {
    const Circle* circ = dynamic_cast<const Circle*>(s); //friend help me do this!!!

    if(circ) {
      if (radius < circ->radius) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
        return false;
    }

  }

virtual void print() {
  cout << "Circle with radius: " << radius << endl;
}

~Circle() {

}

};


#endif
