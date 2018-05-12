#include <iostream>
using namespace std;

int main() {
	int inputN, outputPrime, i, j, prime;
	cin >> inputN;

	for (i = 2; i < inputN; i++) { //since 1 is odd, start with 2
		prime = 0; //is i a prime?
		for (j = 2; j <= i/2; j++) {
			if(i % j == 0) { //not prime
				prime = 1;
				break;
			}
		}
	if (prime == 0 && inputN != 1) 
		cout << i << endl;
	}
	return 0;
	

	
}

