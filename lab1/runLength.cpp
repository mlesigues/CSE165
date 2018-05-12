#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	char holdThis; //this is like the keyword that we want to print out
	int printOut;
	string outThis = "";

	while (true) {
		cin >> holdThis >> printOut; //reads the keyword and how many times to print out
		if (printOut >= 0) { //as long as it is not negative, because duh
			while (printOut > 0) { //this printout how many times to do the thing
				outThis = outThis + holdThis;
				printOut--;
			}
		}
		else if (printOut == -1) {//this indicates new line!
			outThis = outThis + "\n";
		}
		else if (printOut == -2)  //exits the program
			break;
		}
		cout << outThis; //prints everything
		return 0;
	
}


