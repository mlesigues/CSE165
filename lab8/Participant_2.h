#ifndef Participant_h
#define Participant_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#include "Data.h"
#include "Sortable.h"

using namespace std;

class Participant : public Sortable { //extend the base class
public:
  static bool(*comp_cb)(const Participant*, const Participant*);

  //must contain string, int & double
  string name;
  int age;
  double score;

  Participant() {//default constructor
    name = " ";
    age = 0;
    score = 0.0;
  }

  Participant(string nameS, int ageS, double scoreS) {
  /*  this->name = name;
    this->age = age;
    this->score = score;*/
    name = nameS;
    age = ageS;
    score = scoreS;
  }

virtual bool compare(const Sortable* s) { //do the same thing here in Circle.h
  const Participant *part = dynamic_cast<const Participant*>(s);
  if (part) {
    if(comp_cb(this, part))
      return false;
    else
      return true;
    }
    else
      return false;
}

virtual void print() { //print the name, age, and score separated by a tab character.
  cout << name << "\t" << age << "\t" << score << endl;
}

~Participant() {
  }
};

#endif
