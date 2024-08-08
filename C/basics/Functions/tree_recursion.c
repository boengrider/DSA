#include <stdio.h>

void foo(int);

int main() {

    foo(3);

}

void foo(int n) {
    if(n > 0) {
        printf("%d\n", n);
        foo(n-1);
        foo(n-1);
    }
}