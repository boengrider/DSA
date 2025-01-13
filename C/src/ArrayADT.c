/******************************************************
 * ArrayADT functionality implementation
 ******************************************************/
#include "ArrayADT.h"


/***************************************
 * Linear search. No shift
****************************************/
int LinearSearch(struct ArrayADT *arp, int value) {

    for(int i = 0; i < arp->length; i++) {
        if(value == arp->A[i])
            //found
            return i;
    }

    //not found
    return -1;
}

//===================================================
// Definitions of operations supported by ArrayADT ADT
//===================================================

/*********************************
 Get elemenent at specified index
*********************************/
void Get(struct ArrayADT *arp, int index) {
    int __index;
    printf("Enter index of an element\n");
    scanf("%d", &__index);
    if(__index >= arp->size) {
        printf("Index %d is out of bounds\n", __index);
    } else {
        printf("%d\n", arp->A[__index]);
    }
}

/************************************
 Display current contents of an ArrayADT
************************************/
void Display(struct ArrayADT *arp) {
    for(int i = 0; i < arp->length; ++i) {
        printf("%d ", arp->A[i]);
    }
    printf("\n");
}

/******************************
 Append to the end of an ArrayADT
 given it's not full. 
*******************************/
void Append(struct ArrayADT *arp, int value) {
    int __value;
    if(arp->length < arp->size) {
        arp->A[++arp->length] = value;
    } else {
        printf("ArrayADT is full\n");
    }

    arp->sorted = UNSORTED;
}

/*********************************
 Get length i.e current number of 
 elements stored in an ArrayADT
*********************************/
void Length(struct ArrayADT *arp) {
    printf("%d\n",arp->length);
}

/*********************************
 Swap two elements within an ArrayADT
**********************************/
void Swap(struct ArrayADT *arp, int value, int index) {
    if(index >= arp->size || index < 0) {
        printf("\nIndex out of bounds\n");
    } else { 
        arp->A[index] = value;
    }
}

/*************************************
 Insert element at the specified index
 Nicer version
 No appending. Simply insert at the 
 requested index. Only check if it's 
 not beyond the ArrayADT boundaries
 *************************************/
void Insert(struct ArrayADT *arp, int value, int index) {
   
    if(index >= arp->size || index < 0) {
        printf("\nIndex out of bounds\n");
    } else {
        for(int i = arp->length - 1; i > index; i--) {
            arp->A[i] = arp->A[i-1];
        }

        arp->A[index] = value;
    }

    //Only increase size if the wasn't full before inserting
    if(arp->length < arp->size) {
        arp->length++;

    }

    arp->sorted = SORTED;
}

/***************************************
 Delete element at the specified index
 and shift all the elements to the right
 one position to the left
 ***************************************/
int Delete(struct ArrayADT *arp, int index) {

    if(index > arp->size || index < 0) {
        return -1; //Nothing was deleted
    } else {
        for(int i = index; i < arp->length - 1; i++) {
            arp->A[i] = arp->A[i+1];
        }

        if(arp->length > 0) {
            arp->length--;
        }

        return index; //Return index of the deleted item
    }
}


/*****************************************
 * Linear search with shift left by one
 * Since linear search always has to scan
 * the entire array we shift the searched
 * for element closer to the begining
 * of the array, wich should give us
 * better performance if the same element
 * is searched for again
 *****************************************/
int LinearSearchWithShift(struct ArrayADT *arp, int value) {
   
    for(int i = 0; i < arp->length; i++) {
        if(value == arp->A[i]) {
            int __tmp = arp->A[i];                //found
            int __iPrev = (i == 0) ? 0 : (i - 1); //do not shift element past index 0
            arp->A[i] = arp->A[__iPrev];          //shift element closer to the start 
            arp->A[__iPrev] = __tmp;
            
            return i;
        }
    }

    //not found
    return -1;
}

/*****************************************
 * Binary search
 *****************************************/
int BinarySearch(struct ArrayADT *arp, int value) {
   
    int __low,__high;
    __low = 0;
    __high = arp->length;

    if(arp->sorted = UNSORTED) {
        BubbleSort(arp);
    }
    
    while(__low <= __high) {
        int __mid = (__low + __high) / 2;
        if(value == arp->A[__mid]) {
            return __mid;
        } else if (value < arp->A[__mid])
        {
            __high = __mid - 1;
        } else if (value > arp->A[__mid]) {
            __low = __mid + 1;
        }
    }

    //not found
    return -1;
}

void BubbleSort(struct ArrayADT* arp) {
    int swaps;
    do
    {
        //we need at least one pass even if the ArrayADT is already sorted
        swaps = 0;
        for(int i = 0; i < arp->length; i++) {
            int tmp;
            if(arp->A[i] > arp->A[i+1]) {
                tmp = arp->A[i+1];
                arp->A[i+1] = arp->A[i];
                arp->A[i] = tmp;
                swaps = 1;
            }
        }
    } while (swaps > 0);

    arp->sorted = SORTED;
}