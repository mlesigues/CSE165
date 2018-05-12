#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str1;
	//int i;
	vector<string>vec1; //because we have to use vectors
	getline(cin, str1); //getting the input here

	while(str1.compare("quit") != 0) { //the trigger word
		if(str1.size() == 1) {
			for(int i = 0; i < vec1.size(); ++i) {
				if(vec1[i].substr(0,1) == str1) {
					vec1.push_back(vec1[i]);
					break;
				}
			}
		}
		else {
			vec1.push_back(str1);
		}
		getline(cin, str1);
	}
	for(int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << endl;
	}
//	return 0;
}
