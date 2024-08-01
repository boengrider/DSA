//Consecutive allocations
#include <iostream>

using namespace std;
int main() {

    //Declare array of pointers to integers
    int *p[20];

    //Allocate space
    for(int i = 0; i != 20; ++i) {
        p[i] = new int;
        *p[i] = (i + 1) * 10;
    }


   

    //Derefercing pointers as they're stored in the array
    for(int i = 0; i != 20; ++i)
        cout << p[i] << " -> " << *p[i] << endl;
    

   
    /**
    //Starting from p[0]
    for(int i = 0; i != 20; ++i)
        cout << p[0 + i] << " -> " << *p[0 + i] << endl;
    **/

    //Separate allocations are served from the same contignous area
}