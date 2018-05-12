#ifndef Entry_h
#define Entry_h
#include <string>
#include <iostream>
using namespace std;

struct Entry {
	string firstname;
	string lLastname;
	string emailA;

	/*Entry(string firstname, string lastname, string email) {
		firstname = name;
		lastname = lastname;
		email = emailAdd;
	}

/*	string getFirstname() {
		return firstname;
	}
	string getLastname() {
		return lastname;
	}
	string getEmail() {
		return email;
	}
*/
	void setName(string name){
		firstname = name;
	}
	void setLastname(string lastname) {
		lLastname = lastname;
	}
	void setEmail(string email) {
		emailA = email;
	}

	//print function
	void print() {
	cout << "First name: " << firstname << endl;
	cout << "Last name: " << lLastname << endl;
	cout << "Email: " << emailA << endl;
	}


};





#endif
