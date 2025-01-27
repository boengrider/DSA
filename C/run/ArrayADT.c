#include "ArrayADT.h"
#include <stdio.h>
#include <errno.h>

#define LENGTHA 15
#define LENGTHB 14
#define LENGTHC 10
void isSorted(struct ArrayADT*);
void printState(struct ArrayADT*);
void sortOrder(struct ArrayADT*); 

int main() {

    
    struct ArrayADT ar = {SORTED, MAX_SIZE, LENGTHC, {1,2,3,4,5,6,7,8,9,10}};

    struct ArrayADT *par = &ar;
   
    for(int i = 11; i <= 16; i++) {
        printState(par);
        
        if(Insert(par, i, par->length) < 0)
            printf("\nArray is full\n");
    }

    _BubbleSort(par);
    printState(par);

    Reverse(par);
    printState(par);


     for(int i = 0; i <= par->length; i++) {
        Set(par, i, 0);
    }


    
    _BubbleSort(par);
    printState(par);

}

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
    printf(" Contents -> ");
    Display(arp);
}