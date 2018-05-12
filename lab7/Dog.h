#ifndef Dog_h
#define Dog_h

#include "Animal.h"

class Dog : public Animal {
    string name;
    int age;

  public:
    Dog(string name, int age) {
        cout << "Creating Dog" << endl;
        //names = "name";
        //ages = 0;
        setName(name);
        setAge(age);
        //this->names = names;
        //this->ages = ages;
        //name = "name";
        //age = 0;
    }

  /*  void display (const vector<Animal*> & list){

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
    }*/

   ~Dog(){ //deconstructor
        cout << "Deleting Dog" << endl;
    }

    void feed(){
        cout << "A bone, please!" << endl;
    }


};



#endif
