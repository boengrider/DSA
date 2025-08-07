#include "ArrayADT.h"
#include <stdio.h>

#define LENGTH 10

typedef enum header_ {
    SORTING,
    REVERSING,
    DELETING,
    INSERTING,
    SWAPPING,
    SETTING,
    SEARCHING,
    UNION,
    INTERSECTION,
    IS_SORTED
} header_t;

void isSorted(struct ArrayADT*);
void printState(struct ArrayADT*);
void sortOrder(struct ArrayADT*);
void printHeader(header_t);
void printContents(struct ArrayADT*);



int main() {

    
    //Declare and initialize an array of size MAX_SIZE containing LENGTH elements
    struct ArrayADT arh = {UNSORTED, SIZE, 1, {1}};  
    struct ArrayADT arg = {UNSORTED, SIZE, 2, {2,2}};   
    struct ArrayADT arf = {UNSORTED, SIZE, 2, {1,2}};   
    struct ArrayADT are = {UNSORTED, SIZE, SIZE, {1,2,3,4,5}};   
    struct ArrayADT ard = {UNSORTED, SIZE, SIZE, {1,2,3,5,4}};   
    struct ArrayADT arc = {UNSORTED, SIZE, SIZE, {1,1,1,1,1}};   
    struct ArrayADT arb = {UNSORTED, SIZE, SIZE, {1,2,3,4,4}};   
    struct ArrayADT ara = {UNSORTED, SIZE, SIZE, {1,1,1,2,2}};

    
    
   struct ArrayADT *arrays[] = { &ara, &arb, &arc, &ard, &are, &arf, &arg, &arh};
   

   for(int i = 0; i < 8; i++)
   {
        struct ArrayADT *p = arrays[i];
        isSorted(p);
        printContents(p);
        p++;
   }
  

}

//Helper functions
void isSorted(struct ArrayADT *arp) {
    Code __isSorted = IsSorted(arp);

    switch (__isSorted) {
        case ARRAY_SORTED:
            printf("Sorted -> ");
            break;

        case ARRAY_UNSORTED:
            printf("Unsorted -> ");
            break;

        default:
            printf("n/a -> ");  
            break;
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

        case SEARCHING:
            printf("\nSearching for an element\n");
            break;

        case IS_SORTED:
            printf("\nIs sorted ?\n");
            break;

        default:
            break;

    }
}