#ifndef Data_h
#define Data_h
#include <iostream>
#include <vector>
#include "Sortable.h"
using namespace std;

//lab 8, exercise 3

//class Sortable *sorting;
class Data {
//  int numbers;
  vector <int> numberS;
//  vector<int>::iterator it;

public:
  //Data(); //constructor
  void add(int number) { //add number to data set
    //since we're using vector, use push_back
    numberS.push_back(number);
  }

  //sort contents in ascending order
  void add() { //any sorting algorithm, i used bubble sort
    int i, j;
    for (i = 0; i < numberS.size(); i++) {
      for (j = 0; j < numberS.size() - i - 1; j++) {
        if(numberS[j] > numberS[j+1]) {
          //swap
          numberS[j] = numberS[j]+numberS[j+1];
          numberS[j+1] = numberS[j]-numberS[j+1];
          numberS[j] = numberS[j]-numberS[j+1];
        }
      }
    }
  }

  //print contents on a single line, separated w/space
/*  void print() {
    for (int i = 0; i < numberS.size(); i++) {
      cout << numberS[i] << " ";
    //  cout << '\n';
    }
    cout << '\n';
  }
*/
bool compare(const Sortable * s) { //not too sure aboutthis
  if (&s < &s) {
    return true;
  }
  else {
    return 0;
  }

}

void print() {

}
};

/*void Data::add (int number) { //insert number on the vector
  //store a collection (vector) of integers.
  //cin >> number; no need for this
}

void Data::print () {

}

void Data::sort(/) { //bubble sort

}
*/
#endif
