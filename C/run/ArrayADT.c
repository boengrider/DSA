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
    struct ArrayADT ar = {UNSORTED, SIZE, LENGTH, {1,2}};
    struct ArrayADT ara = { UNSORTED, 10, 1, {1}};
    struct ArrayADT arb = { UNSORTED, 10, 2, {3,3}};
    struct ArrayADT arc = { UNSORTED, 10, 3, {3,3, 3}};


    //Declare and initialize pointer to ArrayADT struct
    struct ArrayADT *par = &ar;
    struct ArrayADT *para = &ara;
    struct ArrayADT *parb = &arb;
    struct ArrayADT *parc = &arc;


   printHeader(IS_SORTED);
   printContents(par);
   
   Code isSorted = IsSorted(par);

   switch (isSorted) {
   
        case ARRAY_SINGLE_ELEMENT:
            printf("Array is sorted and continas only one element\n");
            break;

        case ARRAY_TWO_ELEMENTS:
            printf("Array is sorted and contains only two elements\n");
            break;

        case ARRAY_SAME_ELEMENTS:
            printf("Array is sorted composed of the same elements\n");
            break;

        case OTHER:
            printf("Not yet implemented\n");
            break;

        default:
            break;
   }


   printHeader(IS_SORTED);
   printContents(para);
   
   isSorted = IsSorted(para);

   switch (isSorted) {
   
        case ARRAY_SINGLE_ELEMENT:
            printf("Array is sorted and continas only one element\n");
            break;

        case ARRAY_TWO_ELEMENTS:
            printf("Array is sorted and contains only two elements\n");
            break;

        case ARRAY_SAME_ELEMENTS:
            printf("Array is sorted composed of the same elements\n");
            break;

        case OTHER:
            printf("Not yet implemented\n");
            break;

        default:
            break;
   }

   printHeader(IS_SORTED);
   printContents(parb);
   
   isSorted = IsSorted(parb);

   switch (isSorted) {
   
        case ARRAY_SINGLE_ELEMENT:
            printf("Array is sorted and continas only one element\n");
            break;

        case ARRAY_TWO_ELEMENTS:
            printf("Array is sorted and contains only two elements\n");
            break;

        case ARRAY_SAME_ELEMENTS:
            printf("Array is sorted composed of the same elements\n");
            break;

        case OTHER:
            printf("Not yet implemented\n");
            break;

        default:
            break;
   }

   printHeader(IS_SORTED);
   printContents(parc);
   
   isSorted = IsSorted(parc);

   switch (isSorted) {
   
        case ARRAY_SINGLE_ELEMENT:
            printf("Array is sorted and continas only one element\n");
            break;

        case ARRAY_TWO_ELEMENTS:
            printf("Array is sorted and contains only two elements\n");
            break;

        case ARRAY_SAME_ELEMENTS:
            printf("Array is sorted composed of the same elements\n");
            break;

        case OTHER:
            printf("Not yet implemented\n");
            break;

        default:
            break;
   }
   

  


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