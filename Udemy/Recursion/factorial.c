#include <stdio.h>

int factorial(int);

int main() {

    printf("%d\n", factorial(5)); // 120

}

//Recursive function for calculating factorial of a number
//Final result is obtained once the function call is made 
//with n == 1 aka base condition
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
