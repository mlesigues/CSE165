#include <iostream>
#include "refs.h"

using namespace std;
/*void triple(int &number) {
  number *= 3;
}*/

int main(int argc, const char * argv[])
{
    int num = 5;

    triple(num); //this part?? build @ header file

    cout << num << endl;
    return 0;
}
