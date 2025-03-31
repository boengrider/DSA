/*************************************************************
 * ArrayADT abstract data type
 *Supports basic methods such as Display, Search, Sort etc
 ************************************************************/
#include <stdio.h>
#define SIZE 15
#define INSERT_NICE
#define LINEAR_SEARCH
#define LINEAR_SEARCH_WITH_SHIFT

//ArrayADT structure
struct ArrayADT
{
    int sorted;
    int size;   //Maximum number of elements stored
    int length; //Current number of elements stored
    int A[SIZE];//Fixed size of SIZE elements
    
};


//Prototypes of operations supported by an ArrayADT 
extern void Display(struct ArrayADT*);
extern void Get(struct ArrayADT*, int);
extern void Append(struct ArrayADT*, int);
extern void Length(struct ArrayADT*);
extern void Swap(struct ArrayADT*, int, int);
extern void Insert(struct ArrayADT*, int, int);
extern int Delete(struct ArrayADT*, int);
extern int LinearSearch(struct ArrayADT*, int);
extern int LinearSearchWithShift(struct ArrayADT*, int);
extern int BinarySearch(struct ArrayADT*, int);
extern void BubbleSort(struct ArrayADT*);