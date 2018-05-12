#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	ifstream readFile;
	readFile.open("words.txt");
/*	int occur = 0;
	char wordCount[100], count[100];

	cin >> count; //word to count

	while(readFile) {
		readFile >> wordCount;
		if(strcmp(wordCount, count) == 0)
			occur++;
	}

	cout << occur << endl; //prints the occurrences
	readFile.close();
*/

	string wordCount, count;
	int occur = 0;
	int i, input;

	cin >> count; //word to count

	while (readFile >> wordCount) {
		input = 1; //if the word matches in the file with the input
		for (i = 0; i < count.length(); i++) {
			if(!(tolower(count[i] == tolower(wordCount[i])))) {
				input = 0;
				break;
			}
		}
		if (input == 1) //if it's true
			occur++;
		}
		cout << occur << endl;


	return 0;


}
