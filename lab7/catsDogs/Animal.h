#ifndef LA5_Animal_h
#define LA5_Animal_h

#include <iostream>

using namespace std;

class Animal {
    string name;
    int age;
    string something;

public:
  virtual void talk() {
    //something = s;
    cout << "something";
  }

  //string getalk(string something);

    Animal(){
        name = "Generic Name";
        age = 0;
    }

    Animal(string n, int a){
        name = n;
        age = a;
    }

    //create talk here
  /*  Animal(string somethingS) {
      something = somethingS;
    }*/

};

/*string Animal::getalk(string) {
  return something;
}*/


#endif
