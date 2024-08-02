#include <iostream>
using namespace std;

void series(int);
void seriesReversed(int);
int factorial(int);

int main() {
    series(10);         //10 9 8 7 6 5 4 3 2 1
    seriesReversed(10); //1 2 3 4 5 6 7 8 9 10
    int f = factorial(5);
    cout << f << endl;
}


//Prints from 1 to count
//Recursive calls are made,
//but value to print is 
//available BEFORE the recursive call
//returns (stack winding phase)
void series(int count) {

    if(count > 0) {
        cout << count << " ";
        series(count - 1);   
    } else {
        cout << endl;
    }

}

//Prints from count to 1
//Recursive calls are made,
//value to print is
//available AFTER the recursive call
//returns (stack unwinding phase)
void seriesReversed(int count) {

    if(count > 0) {
        seriesReversed(count - 1);
        cout << count << " ";
    } else {
        cout << endl;
    }
}

//Recursive function for calculating factorial of a number
//Final result is obtained once function hits terminating condition
//We obtain the result during stack unwinding phase
int factorial(int n) {
    cout << "n is " << n << ". ";
    //Terminating base condition
    if(n == 1) {
        cout << "Base condition reached with n set to " << n << endl;
        return n;
    } else {
        //Make a recursive call with n decreased by one
        cout << "Making a recursive call with n set to " << n - 1 << endl;
        return n * factorial(n - 1);
    }
}
