#ifndef Generic_h
#define Generic_h

class Generic {
    int data;
public:
	   static int count;

public:
    Generic() {
        data = 0; //we should increment
	//count = 0;
	     count++;
    }

    Generic(int d) { //increment here
        data = d;
	      count = d;
	      count++;
    }


};
int Generic::count; //DO NOT FORGET THIS PART!

#endif
