#ifndef Object_h
#define Object_h
using namespace std;
/*task is to implement Object class. Needs to have a static member named count, which
should be incremented each time a new instance of the class is created. Provide the
appropriate constructors. No need to have destructors.
*/
class Object {
	//int data;
public:
	static int count; //static member

public:
//constructors
//count variable that tracks of how many instances of Object have been created
	Object() {
		count++;
	} //default constructor

	Object(const Object &obj) {
		//data = d.data;
		count++;
	}




};

#endif
