#include <iostream>
#include "FillUp.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Read in the size from the user
    int size;
    cin >> size;
    
    // Create an array of appropriate size
    int* arr;
  //  int arr[size]; //delete this! unneccessary since we're using heap!
    arr = new int[size]; //error is when I put the int before arr, I am overdoing it!!
    
    //delete[] arr;
    // Call the fillUp function
    fillUp(arr, size);
    
    // Call the printPos function on last position
    printPos(arr, size-1);
    
    delete[] arr;
    return 0;
}
