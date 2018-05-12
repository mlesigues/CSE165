#ifndef Data_h
#define Data_h
#include <iostream>
#include <vector>
#include <algorithm>
#include "Sortable.h"
using namespace std;

//class Sortable *sorting;
class Data {
//  use Sortable *s for this
  vector <Sortable*> numberS;
//  vector<int>::iterator it;

public:
  Data(){
    //DO NOT FORGET TO DO THIS!!! IF FORGOTTEN, WILL CAUSES AN UNDEFINED REF!!!
  } //constructor, actually put this
  void add(Sortable* numbs) { //use pointers, not int
    //since we're using vector, use push_back
    numberS.push_back(numbs);
  }

  //sort contents in ascending order(?_)
  void sort() { //any sorting algorithm, i used bubble sort
    //int i, j;
    for (unsigned i = 0; i < numberS.size(); i++) {
      //pointers again
      Sortable *compareThis;
      for (unsigned j = i; j < numberS.size(); j++) { //see if i == j
        if(numberS[j]->compare(numberS[i])) { //use compare, i do not need to make a new compare func
          //swap
          compareThis = numberS[i];
          numberS[i] = numberS[j];
          numberS[j] = compareThis;
        }
      }
    }
  }

  //print contents on a single line, separated w/space
  void print() {
    /*for (int i = 0; i < numberS.size(); i++) {
      cout << numberS[i] << " ";
    //  cout << '\n';
    }
    cout << '\n';*/
    for( vector<Sortable*>::iterator it = numberS.begin(); it != numberS.end(); it++) {
      (*it)->print();
    }
    cout << endl;
  }

  ~Data() {

  }

/*bool compare(const Sortable * s) { //not too sure aboutthis
  if (&s < &s) {
    return true;
  }
  else {
    return 0;
  }

}
*/

};

#endif
