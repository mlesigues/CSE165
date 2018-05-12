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
    /*this->name = name;
    this->age = age;
    this->score = score; */
    name = nameS;
    age = ageS;
    score = scoreS;
}

string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	double getScore() {
		return score;
	}

bool compare(const Sortable* S) { //do the same thing here in Circle.h
/*  const Participant *part = dynamic_cast<const Participant*>(score);
  if (part) {
    if(score < part->score) {
        return false;
    }
    else {
      return true;
    }
  }
  else {
    if (score == part->score) {
      return true;
    }
    else {
      return false;
    }
  }
  return false;
}
*/

//friend help me with this part, because my above code is right but not by the website

		if (score > ((Participant*)S)->getScore())
			return true;

		if (score == ((Participant*)S)->getScore()) {
			if (age < ((Participant*)S)->getAge())
				return true;

			if (age == ((Participant*)S)->getAge()) {
				if (name < ((Participant*)S)->getName())
					return true;
				return false;
			}
			return false;
		}
		return false;
	}

void print() { //print the name, age, and score separated by age tab character.
  cout<<name<< "\t"<<age<<"\t"<<score<<endl;
}

~Participant() {
  }
};

#endif
