#include <stdlib.h>

int main() {
    int *p = new int[20];
    int *q = (int*)malloc(20);

    delete p;
    free(q);
}