#include "/home/vscode/git/DSA/C/Include/ArrayADT.h"


/***************************************
 * Linear search. No shift
****************************************/
int LinearSearch(struct arrayADT *arp) {
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);

    for(int i = 0; i < arp->length; i++) {
        if(__value == arp->A[i])
            //found
            return i;
    }

    //not found
    return -1;
}

//===================================================
// Definitions of operations supported by arrayADT ADT
//===================================================

/*********************************
 Get elemenent at specified index
*********************************/
void Get(struct arrayADT *arp) {
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
 Display current contents of an arrayADT
************************************/
void Display(struct arrayADT *arp) {
    for(int i = 0; i < arp->length; ++i) {
        printf("%d ", arp->A[i]);
    }
    printf("\n");
}

/******************************
 Append to the end of an arrayADT, 
 given it's not full. If the arrayADT
 is not full.
*******************************/
void Append(struct arrayADT *arp) {
    int __value;
    if(arp->length < arp->size) {
        printf("Enter a new value ");
        scanf("%d",&__value);
        arp->A[++arp->length] = __value;
    } else {
        printf("arrayADT is full\n");
    }
}

/*********************************
 Get length i.e current number of 
 elements stored in an arrayADT
*********************************/
void Length(struct arrayADT *arp) {
    printf("%d\n",arp->length);
}

/*********************************
 Swap two elements within an arrayADT
**********************************/
void Swap(struct arrayADT *arp) {
    int __index;
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nIndex at which the value will be stored ");
    scanf("%d",&__index);
    if(__index >= arp->size || __index < 0) {
        printf("\nIndex out of bounds\n");
    } else { 
        arp->A[__index] = __value;
    }
}

/*******************************************
 Insert element at the specified index.
 Move elements to the right by one position,
 poping the last element out 
 *******************************************/
void Insert(struct arrayADT *arp) {
    int __index;
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nEnter index ");
    scanf("%d", &__index);
    
    if(__index >= arp->size || __index < 0)  {
        //Index is beyond arrayADT boundaries
        printf("\nIndex out of bounds\n");
    } else if(arp->length < arp->size) {
        printf("Appending\n");
        //Insert element at the last available position
        arp->A[arp->length] = __value;
        arp->length++;
    } else {
        if(__index == arp->length - 1) {
            //Simply insert at the very end
            arp->A[__index] = __value;
        } else {
            //We have some shifting to do
            int __stlIndex = arp->length - 2; //second to last index

            //Keep shifting until we arpive at the requested index
            while(__stlIndex >= __index) {
                arp->A[__stlIndex + 1] = arp->A[__stlIndex];
                __stlIndex--;
            }
            arp->A[__index] = __value;
        }
    }
}

/*************************************
 Insert element at the specified index
 Nicer version
 No appending. Simply insert at the 
 requested index. Only check if it's 
 not beyond the arrayADT boundaries
 *************************************/
void InsertNice(struct arrayADT *arp) {
    int __index, __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nEnter index ");
    scanf("%d", &__index);

    if(__index >= arp->size || __index < 0) {
        printf("\nIndex out of bounds\n");
    } else {
        for(int i = arp->length - 1; i > __index; i--) {
            arp->A[i] = arp->A[i-1];
        }

        arp->A[__index] = __value;
    }

    //Only increase size if the wasn't full before inserting
    if(arp->length < arp->size) 
        arp->length++;
}

/***************************************
 Delete element at the specified index
 and shift all the elements to the right
 one position to the left
 ***************************************/
void Delete(struct arrayADT *arp) {
    int __index;
    printf("\nEnter index ");
    scanf("%d", &__index);

    if(__index > arp->size || __index < 0) {
        printf("\nIndex out of bound\n");
    } else {
        for(int i = __index; i < arp->length - 1; i++) {
            arp->A[i] = arp->A[i+1];
        }

        if(arp->length > 0)
            arp->length--;
    }
}


/*****************************************
 * Linear search with shift left by one
 *****************************************/
int LinearSearchWithShift(struct arrayADT *arp) {
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);

    for(int i = 0; i < arp->length; i++) {
        if(__value == arp->A[i]) {
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
int BinarySearch(struct arrayADT *arp) {
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);

    int __low,__high;
    __low = 0;
    __high = arp->length;
    
    while(__low <= __high) {
        int __mid = (__low + __high) / 2;
        if(__value == arp->A[__mid]) {
            return __mid;
        } else if (__value < arp->A[__mid])
        {
            __high = __mid - 1;
        } else if (__value > arp->A[__mid]) {
            __low = __mid + 1;
        }
    }

    //not found
    return -1;
}

void BubbleSort(struct arrayADT* arp) {
    int swaps;
    do
    {
        //we need at least one pass even if the arrayADT is
        //already sorted
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
}