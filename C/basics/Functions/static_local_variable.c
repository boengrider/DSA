#include <stdio.h>

int foo();

int global;

int main() {
    int x = foo();
    x = foo();
    x = foo();

    printf("%d\n", x);

}


int foo() {
    int c = 0;
    c++;

    return c;
}

