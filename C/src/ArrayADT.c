/******************************************************
 * ArrayADT functionality implementation
 ******************************************************/
#include "ArrayADT.h"

/***************************************
 * Check whether array is sorted.
 ***************************************/
 Code IsSorted(struct ArrayADT *arp)
 {

    //If there are only two elements, array is sorted
    //since we don't care about the sorting order
    //Same applies if there's single element.
    if(arp->length <= 2)
        return ARRAY_SINGLE_ELEMENT | ARRAY_TWO_ELEMENTS; // 1 or 2 elements e.g [1] or [1,3] or [3,1] or [3,3]

    
    int left,right;
    left = 0;
    right = 1;

    //Identify dissimilar entries
    while(left == right)
    {
       left++;
       right++;

       if(right >= arp->length)
            return ARRAY_SAME_ELEMENTS; // Array contains same elements e.g [3,3,3,3]
    }


    
    return OTHER;
 }
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
    if(index >= arp->capacity || index < 0)
        return -1;
    
    return  arp->A[index];
}

/*********************************
 Set elemenent at specified index
*********************************/
int Set(struct ArrayADT* arp, int index, int value) {
     //out of bounds
    if(index >= arp->capacity || index < 0)
        return -1;

    arp->A[index] = value;
    arp->state = UNSORTED;

    return index;
}


/*********************************
 Get length i.e current number of 
 elements stored in an ArrayADT
*********************************/
int Length(struct ArrayADT *arp) {
    return arp->length;
}

/**************************************
 Insert new element. If array is sorted
 Insert will preserve sortedness, 
 otherwise element is apended at the
 end of the array
**************************************/
int Insert(struct ArrayADT *arp, int value)
{ 
   int last = arp->length - 1;

   if(arp->length == arp->capacity)
   {
        while(value < arp->A[last])
        {
            arp->A[last] = arp->A[last - 1];
            last--;
        }

        arp->A[last] = value;

        return last;
   }

   return 0;
}

/*************************************
 Insert new element at the specified 
 index
 *************************************/
int InsertAt(struct ArrayADT *arp, int value, int index) {
   

   //out of bounds
   if(index >= arp->capacity || index < 0)
        return -1;

   //if array is full last element is popped, otherwise we have some 
   //space to the right, so use that index as last
   int i = (arp->length == arp->capacity) ? arp->length - 1 : arp->length;

   while(i > index) {
        arp->A[i] = arp->A[i - 1];
        i--;
   }

   arp->A[index] = value;

   if(arp->length < arp->capacity)
    arp->length++;

   arp->state = UNSORTED;
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

    if(index >= arp->capacity || index < 0)
        return -1;

    arp->A[index] = value;

    arp->state = UNSORTED;

    return index;
}

/***************************************
 Delete element at the specified index
 and shift all the elements to the right
 one position to the left
 ***************************************/
int Delete(struct ArrayADT *arp, int index) {

    if(index >= arp->capacity || index < 0) {
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
            
            arp->state = UNSORTED;
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
    int __low,__mid,__high;
    __low = 0;
    __high = arp->length;

    
    while(__low <= __high)
    {
        __mid = (__low + __high) / 2;

        if(value == arp->A[__mid])
            return __mid;

        if(value < arp->A[__mid])
            __high = __mid - 1;

        if(value > arp->A[__mid])
            __low = __mid + 1;
    }

    return -1;
}

void BubbleSort(struct ArrayADT *arp) {
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

    arp->state = SORTED;
}


int SortedOrder(struct ArrayADT *arp) {
    
    //there's only one element
    if(arp->length <= 1)
        return ORDER_OTHER;
    //array is unsorted
    if(arp->state == UNSORTED) {
        return ORDER_UNSORTED;
    }
    
    //array's sorted. Determine state
    int i = 0;
    while(i < arp->length - 1) {
        //loop as long as two neighbours are equal
        if(arp->A[i] == arp->A[i+1]) {
            i++;
        } else {
            break;
        }
    }

    //all elements are the same value
    if(i == arp->length - 1) 
        return ORDER_OTHER;

    //descending order
    if(arp->A[i] > arp->A[i+1]) 
        return ORDER_DESCENDING;
    
    //ascending order
    if(arp->A[i] < arp->A[i+1]) 
        return ORDER_ASCENDING;
    
    return ORDER_OTHER;
};

double Median(struct ArrayADT *arp) {

    if(arp->state == UNSORTED)
        return 0;

    int midPoint = arp->length / 2;
    //Odd number of elements
    if(arp->length % 2 ) 
        return (double)arp->A[midPoint];
        
    //Even number of elements
    return (double)(arp->A[midPoint] + arp->A[midPoint - 1]) / 2;
    
}

int Mode(struct ArrayADT *arp)
{

}

void _QuickSort(struct ArrayADT* arp) {


    int pivot = arp->length - 1; // Pick the last element as a pivot
    int i = -1;
    int j = 0;
    int tmp;

    while(j < pivot) {
        if(arp->A[j] < arp->A[pivot]) {
            tmp = arp->A[++i];
            arp->A[i] = arp->A[j];
            arp->A[j] = tmp;
        }

        j++;
    }

    tmp = arp->A[i+1];
    arp->A[i+1] = arp->A[pivot];
    arp->A[pivot] = tmp;

}
