#include <stdio.h>

int* foo() {

    static int fooCounter = 10;

    return &fooCounter;

}

int main() {

    int *fooCounterp = foo();

    printf("%d\n", *fooCounterp);

    return 0;

}