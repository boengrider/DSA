#include <iostream>

int main() {

    int a = 10;

    int &r = a;

    r = 20;

    printf("%d\n", a);
}