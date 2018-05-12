#include "Animal.h"
#include "Dog.h"
#include "display.h"
#include <iostream>
#include <vector>

using namespace std;
//reads integer N, followed by N lines (line contains a char, string and int, separated by space)
//char : A(generic animal) or D(dog)
//string: animal's name
//int : animal's age

//put change here for animal.h
/*Animal::Animal(){
    cout << "Creating Generic Animal" << endl;
  //  name = "Generic Animal";
  //  age = 0;
  name = nameS;
  age = ageS;
};
*/

class newAnimal: public Animal {
  string name;
  int age;

public:
  newAnimal(string nameS, int ageS){
    //  cout << "Creating Generic Animal" << endl;
    //  name = "Generic Animal";
    //  age = 0;
    name = nameS;
    age = ageS;
    setName(nameS);
    setAge(ageS);
  }

    /*  string getName() const{
          return name;
      }

      void setName(string name){
          this->name = name;
      }

      int getAge() const {
          return age;
      }

      void setAge(int age){
          this->age = age;
      }*/
};

int main(int argc, const char * argv[]) {
  int N;
  cin >> N;
  char type;
  string name;
  int age;

  //create a vector of pointers to Animal
  vector<Animal*> animalVector;

  for (int i = 0; i < N; i++) {
    cin >> type >> name >> age;

    //check if it is A or D, then use push_back
    if(type == 'A') {
      animalVector.push_back(new newAnimal(name, age));
    }
    else {
      animalVector.push_back(new Dog(name, age));
    }
  }

  //then call the display
  display(animalVector);

  return 0;

}
