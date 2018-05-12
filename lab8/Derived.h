#ifndef Derived_h
#define Derived_h
#include <iostream>
using namespace std;
#include "ADT.h"

class Derived: public ADT {

public:
  //instead of just putting void functionName()
  //i actually have to put a cout statement inside of it
  void doSomething() {
    cout << "I did something" << endl;
  }
  void doSomethingElse() {
    cout << "I did something else" << endl;
  }
  void dontDoThis() { //haha
    cout << "I did not do this" << endl;
  }


};


#endif
