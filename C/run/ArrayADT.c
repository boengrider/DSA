#include "ArrayADT.h"
#include <stdio.h>

#define LENGTH 10

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
void printContents(struct ArrayADT*);



int main() {

    
    //Declare and initialize an array of size MAX_SIZE containing LENGTH elements
    struct ArrayADT ar = {UNSORTED, SIZE, LENGTH, {1,3,5,8,2,9,4,7,6,10}};

    //Declare and initialize pointer to ArrayADT struct
    struct ArrayADT *par = &ar;
   

    for(int i = 11; i <= 16; i++) {
        printState(par);
        printHeader(INSERTING);
        if(InsertAt(par, i, par->length) < 0)
            printf("\nArray is full. %d is not stored\n", i);
    }

    printHeader(SORTING);
    BubbleSort(par);
    printState(par);
    printContents(par);

    printHeader(REVERSING);
    Reverse(par);
    printState(par);
    printContents(par);

    printHeader(REVERSING);
    Reverse(par);
    printState(par);
    printContents(par);

    printHeader(DELETING);
    Delete(par, 14);
    printState(par);
    printContents(par);

    printHeader(INSERTING);
    InsertAt(par, 3, 14);
    printState(par);
    printContents(par);

    printHeader(SORTING);
    BubbleSort(par);
    printState(par);
    printContents(par);

    printHeader(INSERTING);
    Insert(par, 14);
    printState(par);
    printContents(par);

    printHeader(INSERTING);
    Insert(par, 15);
    printState(par);
    printContents(par);

}

//Helper functions
void isSorted(struct ArrayADT *arp) {
    if(arp->state == SORTED) { 
        printf("True\n");
    } else {
        printf("False\n");
    }
}

void isFull(struct ArrayADT *arp) {
    if(arp->length == arp->capacity) {
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
}

void printContents(struct ArrayADT *arp)
{
    for(int i = 0; i < arp->length; i++)
    {
        printf("%d ", arp->A[i]);

    }

    printf("\n");
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