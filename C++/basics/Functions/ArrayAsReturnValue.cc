#include <iostream>

int* allocateArrayA(int);
void* allocateArrayB(int);

int main() {

    int *pArrayA = allocateArrayA(5);
    int *pArrayB = (int*)allocateArrayB(5);

    for(int i = 0; i < 5; i++) {
        printf("%d\n", pArrayA[i]);
    }

    for(int j = 0; j < 10; j++) {
        printf("%d\n", pArrayB[j]);
    }

}

int* allocateArrayA(int size) {

    return (int*)malloc(size * sizeof(int));

}

void* allocateArrayB(int size) {

    return malloc(size * sizeof(int));

}