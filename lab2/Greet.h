#ifndef Greet_h
#define Greet_h
// We should include <string> here
#include <string>
using namespace std;

// Implement your "greet" function below

//void(*polite)(string); //pointer function to polite func

//void(*rude)(string); //pointer function to rude func

void greet(string name, void(*polite)(string)) { //because it should take a string
	polite(name);				 // and a function pointer, which is 
	//greet = &polite;			 //polite	
}

/*void greet(string name, void(*rude)(string)) { //because it should take a string
	rude(name);
}*/
#endif /* Greet_h */
