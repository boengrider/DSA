#include <stdio.h>


int* foo();

int main() {

   int *fooCounterp = foo();                            // We can call this despite the compiler warning
   printf("Value of fooCounter -> %d\n", *fooCounterp); // Dereferencing the pointer however, causes exception
   
   return 0;

}

//Causes compiler warning: -Wreturn-local-addr
int* foo() {
    static int fooCounter = 10;

    return &fooCounter;
    
}

