#include <iostream>
using namespace std;

//Prototype
int factorial(int);

int main() {
    int result = factorial(5);

    cout << result << endl;
}

//Recursive function for calculating factorial on a number
//Final result is obtained once function hits terminating condition
//We obtain the result during stack unwinding phase
int factorial(int n) {
    //Terminating base condition
    if(n == 1) {
        return n;
    } else {
        //Make a recursive call with n decreased by one
        return n * factorial(n - 1);
    }
}

