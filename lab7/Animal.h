#ifndef LA4_Animal_h
#define LA4_Animal_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
    string name;
    int age;


public:


    Animal() {
      cout << "Creating Generic Animal" << endl;
      name = "Generic Animal";
      age = 0;
    }

    //don't customize the above, make a new one!
    /*Animal(string nameS, int ageS){
        cout << "Creating Generic Animal" << endl;
      //  name = "Generic Animal";
      //  age = 0;
      name = nameS;
      age = ageS;
    }*/

    void display (const vector<Animal*> & list){

    }

    string getName(){
        return name;
    }

    void setName(string name){
        this->name = name;
    }

    int getAge(){
        return age;
    }

    void setAge(int age){
        this->age = age;
    }

    ~Animal(){
        cout << "Deleting Generic Animal" << endl;
    }

    void feed(){
        cout << "Some food, please!" << endl;
    }

};

#endif
