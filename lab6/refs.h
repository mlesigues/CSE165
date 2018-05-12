#ifndef res_h//OMFGGG don't forget this part
#define refs_h

//this is where i define triple
//triple is some# * 3, like x*3 =3x

/*void triple(int &number) { //triple should only take 1 argument
	//int three = 3;
	//triple = number * 3;
	triple = number * 3;
}*/

/*void triple(const int &number) { //triple should only take 1 argument
	//int three = 3;
	//triple = number * 3;
	//number = number * 3;
	int& aNum = const_cast<int&>(number);
	3*aNum;
};*/
/*class A {
public:
int triple(int &number) { //triple should only take 1 argument
	//int three = 3;
	//triple = number * 3;
		number = number * 3;
	}
};*/

void triple(int& number) {
	//return (number *= 3);
	number *= 3;
};






#endif
