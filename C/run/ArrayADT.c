#include "ArrayADT.h"
#include <stdio.h>

void isSorted(struct ArrayADT*);

int main() {

    struct ArrayADT myArray = {UNSORTED, 15, 3, {1,2,3}};

    printf("Array after inialization is ");
    isSorted(&myArray);

    int value = BinarySearch(&myArray, 3);
    printf("Array after binary search method called is ");
    isSorted(&myArray);

    Delete(&myArray, 0);
    printf("Array after delete method called is ");
    isSorted(&myArray);

    printf("New array lenght is %d\n", myArray.length);

    Insert(&myArray, 90, 0);
    printf("Array after insert method called is ");
    isSorted(&myArray);

    printf("New lenght of the is %d\n", myArray.length);
    printf("Item 90 at index %d\n", BinarySearch(&myArray,90));
    printf("Array after binary search method called is ");
    isSorted(&myArray);

    





}

void isSorted(struct ArrayADT* arp) {
    if(arp->sorted) { 
        printf("sorted\n");
    } else {
        printf("not sorted\n");
    }
}