/*************************************************************
 * ArrayADT (Abstract data type)
 * Supports basic methods such as Display, Search, Sort etc
 ************************************************************/
#include <stdio.h>
#define MAX_SIZE 15
#define INSERT_NICE
#define LINEAR_SEARCH
#define LINEAR_SEARCH_WITH_SHIFT
#define SORTED 1
#define UNSORTED 0

//ArrayADT structure
struct ArrayADT
{
    int sorted;
    int size;   //Maximum number of elements stored
    int length; //Current number of elements stored
    int A[MAX_SIZE];//Fixed size of SIZE elements
    
};

enum Insert {
    PRESERVE_SORTED,
    IGNORE_SORTED
};

//Operations supported by an ArrayADT 
extern void Display(struct ArrayADT*);
extern int Get(struct ArrayADT*, int);
extern int Set(struct ArrayADT*, int, int);
extern int Max(struct ArrayADT*);
extern int Min(struct ArrayADT*);
extern long Sum(struct ArrayADT*);
extern long Avg(struct ArrayADT* arp);
extern int Length(struct ArrayADT*);
extern int Insert(struct ArrayADT*, int, int, enum Insert);
extern int Delete(struct ArrayADT*, int);
extern int LinearSearch(struct ArrayADT*, int);
extern int LinearSearchWithShift(struct ArrayADT*, int);
extern int BinarySearch(struct ArrayADT*, int);
extern void _BubbleSort(struct ArrayADT*);
extern int Swap(struct ArrayADT*, int, int);
extern void Reverse(struct ArrayADT* arp);