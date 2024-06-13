#include <stdio.h>
#include <stdlib.h>


//Forward declaration
void fun(int [], int);
int* allocateArray(int);

int main() {

    //Array A declared and initialized on main's stack
    int A[5] = { 1, 2, 3, 4, 5};

    //A points to the 1st element of the array
    fun(A, 5);

    int i;

    for(i = 0; i < 5; i++) {
        printf("%d\n", A[i]);
    }

    //Pointer to the 1st element, this is the same as the previous call
    fun(&A[0], 5);

    for(i = 0; i < 5; i++) {
        printf("%d\n", A[i]);
    }

    int *heapArray = allocateArray(10);

    for(i = 0; i < 10; i++) {
        printf("%d\n", heapArray[i]);
    }

    free(heapArray);


}

void fun(int array[], int size) {


    for(int i = 0; i < size; i++) {
        if(array[i] % 2 == 0) {
            array[i] = array[i] * 10;
        }
    }

}

int* allocateArray(int size) {

    int *p;
    p = (int*)malloc(size * sizeof(int));

    return p;
}
