#include "ArrayADT.h"
#include <stdio.h>
#include <errno.h>

#define LENGTH 5

typedef enum header_ {
    SORTING,
    REVERSING,
    DELETING,
    INSERTING,
    SWAPPING,
    SETTING
} header_t;

void isSorted(struct ArrayADT*);
void printState(struct ArrayADT*);
void sortOrder(struct ArrayADT*);
void printHeader(header_t);



int main() {

    
    //Declare and initialize an array of size MAX_SIZE containing LENGTH elements
    struct ArrayADT ar = {UNSORTED, MAX_SIZE, LENGTH, {10,80,30,90,40}};

    //Declare and initialize pointer to ArrayADT struct
    struct ArrayADT *par = &ar;
   

    printState(par);

    printHeader(SORTING);
    _QuickSort(par);
    printState(par);



}

//Helper functions
void isSorted(struct ArrayADT *arp) {
    if(arp->sorted == SORTED) { 
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void isFull(struct ArrayADT *arp) {
    if(arp->length == arp->size) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void sortOrder(struct ArrayADT *arp) {
    switch (SortedOrder(arp))
    {
    case ORDER_ASCENDING:
        printf("Ascending\n");
        break;
    
    case ORDER_DESCENDING:
        printf("Descending\n");
        break;

    case ORDER_OTHER:
        printf("Other\n");
        break;

    case ORDER_UNSORTED:
        printf("Unsorted\n");
        break;
    }

}


void printState(struct ArrayADT *arp) {
    printf("\nCurrent array's sate:\n");
    printf(" Length -> %d\n", Length(arp));
    printf(" Sorted -> ");
    isSorted(arp);
    printf(" Sorted order -> ");
    sortOrder(arp);
    printf(" Full -> ");
    isFull(arp);
    printf(" Median value -> %f\n",Median(arp));
    printf(" Contents -> ");
    Display(arp);
}

void printHeader(header_t header) {

    switch(header) {
        case SORTING:
            printf("\nSorting the array\n");
            break;

        case REVERSING:
            printf("\nReversing the array\n");
            break;

        case DELETING:
            printf("\nDeleting an element from the array\n");
            break;

        case INSERTING:
            printf("\nInserting an element in the array\n");
            break;

        case SWAPPING:
            printf("\nSwapping elements\n");
            break;

        case SETTING:
            printf("\nSetting an element\n");
            break;

    }
}