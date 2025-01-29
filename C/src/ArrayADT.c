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
int Get(struct ArrayADT *arp, int index) {
    //out of bounds
    if(index >= arp->size || index < 0)
        return -1;
    
    return  arp->A[index];
}

/*********************************
 Set elemenent at specified index
*********************************/
int Set(struct ArrayADT* arp, int index, int value) {
     //out of bounds
    if(index >= arp->size || index < 0)
        return -1;

    arp->A[index] = value;
    arp->sorted = UNSORTED;

    return index;
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


/*********************************
 Get length i.e current number of 
 elements stored in an ArrayADT
*********************************/
int Length(struct ArrayADT *arp) {
    return arp->length;
}


/*************************************
 Insert element at the specified index
 Nicer version
 No appending. Simply insert at the 
 requested index. Only check if it's 
 not beyond the ArrayADT boundaries
 Last element is popped 
 *************************************/
int Insert(struct ArrayADT *arp, int value, int index) {
   

   //not implemented yet
   /* switch(params) {
    case PRESERVE_SORTED:

    case IGNORE_SORTED:

    default:
   } */


   //out of bounds
   if(index >= arp->size || index < 0)
        return -1;

   //if array is full last element is popped, otherwise we have some 
   //space to the right, so use that index as last
   int i = (arp->length == arp->size) ? arp->length - 1 : arp->length;

   while(i > index) {
        arp->A[i] = arp->A[i - 1];
        i--;
   }

   arp->A[index] = value;

   if(arp->length < arp->size)
    arp->length++;

   arp->sorted = UNSORTED;
   return index;
   
}


/**************************************
 * Swap
 * Removes element at the specified index
 * and replaces it with the provided value
 * if successfull index of the new value is 
 * returned, -1 otherwise
 */
int Swap(struct ArrayADT *arp, int value, int index) {

    if(index >= arp->size || index < 0)
        return -1;

    arp->A[index] = value;

    arp->sorted = UNSORTED;

    return index;
}

/***************************************
 Delete element at the specified index
 and shift all the elements to the right
 one position to the left
 ***************************************/
int Delete(struct ArrayADT *arp, int index) {

    if(index >= arp->size || index < 0) {
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

/*******************************
 * Return maximum value stored
 * in the array
 ********************************/
int Max(struct ArrayADT *arp) {

    int max = arp->A[0];

    for(int i = 1; i < arp->length; i++) {
        if(arp->A[i] > max)
            max = arp->A[i];
    }

    return max;
}

/********************************
 * Return minimum value stored
 * in the array
 ********************************/
int Min(struct ArrayADT *arp) {

    int min = arp->A[0];

    for(int i = 1; i < arp->length; i++) {
        if(arp->A[i] < min)
            min = arp->A[i];
    }

    return min;
}

/************************************
 * Return the sum of all the elements
 ************************************/
long Sum(struct ArrayADT* arp) {

    long sum = 0;

    for(int i = 0; i < arp->length; i++) {
        sum += arp->A[i];
    }

    return sum;
}

/*********************************
 * Return the average value stored
 **********************************/
long Avg(struct ArrayADT* arp) {

    long sum = Sum(arp);

    return sum / arp->length;
}

/***********************************
 * Reverse
 ***********************************/
void Reverse(struct ArrayADT* arp) {

   int last = arp->length - 1;

   for(int i = 0; i < arp->length / 2; i++) {
    int __tmp;
    __tmp = arp->A[i];
    arp->A[i] = arp->A[last - i];
    arp->A[last - i] = __tmp;
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
            
            arp->sorted = UNSORTED;
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

    if(arp->sorted == UNSORTED) {
        _BubbleSort(arp);
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

void _BubbleSort(struct ArrayADT *arp) {
    int swaps;

    do
    {
        //we need at least one pass even if the ArrayADT is already sorted
        swaps = 0;
        for(int i = 0; i < arp->length - 1; i++) {
          
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

int Merge(struct ArrayADT *arpa, struct ArrayADT *arpb) {
    
}

int SortedOrder(struct ArrayADT *arp) {
    
    //there's only one element
    if(arp->length <= 1)
        return ORDER_OTHER;

    if(arp->sorted == UNSORTED) {
        return ORDER_UNSORTED;
    }
    
    int i = 0;
    while(i < arp->length - 1) {
        if(arp->A[i] == arp->A[i+1]) {
            i++;
        } else {
            break;
        }
    }

    //all elements are the same value
    if(i == arp->length - 1) 
        return ORDER_OTHER;


    if(arp->A[i] > arp->A[i+1]) 
        return ORDER_DESCENDING;
    

    if(arp->A[i] < arp->A[i+1]) 
        return ORDER_ASCENDING;
    
};

double Median(struct ArrayADT *arp) {

    int offset = arp->length % 2 + 1
}
