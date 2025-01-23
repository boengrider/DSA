#include "ArrayADT.h"
#include <stdio.h>
#include <errno.h>

#define LENGTHA 15
#define LENGTHB 14
#define LENGTHC 10
void isSorted(struct ArrayADT*);
void printState(struct ArrayADT*);

int main() {

    
    struct ArrayADT ar = {SORTED, MAX_SIZE, LENGTHC, {1,2,3,4,5,6,7,8,9,10}};

    struct ArrayADT *par = &ar;
   
    for(int i = 11; i <= 16; i++) {
        printState(par);
        
        if(Insert(par, i, par->length) < 0)
            printf("Array is full\n");
    }


    Reverse(par);
    printState(par);
    _BubbleSort(par);
    printState(par);
   
   
    
    



    /**
    printf("\nLinear search called. Searching element 12\n");
    printf("Element found at index %d\n",  LinearSearch(&myArray, 12));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nBinary search called. Searching element 15\n");
    printf("Element found at index %d\n",  BinarySearch(&myArray, 15));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nLinear search with shift called. Searching element 13\n");
    printf("Element found at index %d\n",  LinearSearchWithShift(&myArray, 13));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nLinear search with shift called. Searching element 13\n");
    printf("Element found at index %d\n",  LinearSearchWithShift(&myArray, 13));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nBinary search called. Searching element 15\n");
    printf("Element found at index %d\n",  BinarySearch(&myArray, 15));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nInserting element 100 at index 9\n");
    Insert(&myArray, 100, 9);
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nSwapping element at index 9 with value 99\n");
    Swap(&myArray, 99, 9);
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nSetting element at index 9 to 100\n");
    Set(&myArray, 9, 100);
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nMax value stored in the array %d\n",Max(&myArray));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nMin value stored in the array %d\n",Min(&myArray));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nSum of the values stored in the array %ld\n",Sum(&myArray));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nAverage value stored in the array %ld\n",Avg(&myArray));
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

    printf("\nReversing the array\n");
    Reverse(&myArray);
    printf("Array state:\n");
    printf(" Length -> %d\n", Length(&myArray));
    printf(" Sorted -> ");
    isSorted(&myArray);
    printf(" Contents -> ");
    Display(&myArray);

   **/





}

void isSorted(struct ArrayADT* arp) {
    if(arp->sorted == SORTED) { 
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void isFull(struct ArrayADT* arp) {
    if(arp->length == arp->size) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}


void printState(struct ArrayADT *arp) {
    printf("\nCurrent array's sate:\n");
    printf(" Length -> %d\n", Length(arp));
    printf(" Sorted -> ");
    isSorted(arp);
    printf(" Full -> ");
    isFull(arp);
    printf(" Contents -> ");
    Display(arp);
}