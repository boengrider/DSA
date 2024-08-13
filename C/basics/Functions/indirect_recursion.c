#include <stdio.h>

int foo(int);
int bar(int);

int main() {

    foo(100);

}

int foo(int n) {
    if(n>0) {
        printf("%d\n", n);
        bar(n-1);
    }
};

int bar(int n) {
    if(n>1) {
        printf("%d\n", n);
        foo(n/2);
    }
}