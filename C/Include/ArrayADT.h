/*************************************************************
arrayADT abstract data type
Supports basic methods such as Display, Search, Sort etc
*************************************************************/
#include <stdio.h>
#define SIZE 15
//arrayADT structure
struct arrayADT
{
    int A[SIZE];//Fixed size of SIZE elements
    int size;   //Maximum number of elements stored
    int length; //Current number of elements stored
};

#define INSERT_NICE
#define LINEAR_SEARCH
#define LINEAR_SEARCH_WITH_SHIFT


//Prototypes of operations supported by an arrayADT 
extern void Display(struct arrayADT*);
extern void Get(struct arrayADT*);
extern void Append(struct arrayADT*);
extern void Length(struct arrayADT*);
extern void Swap(struct arrayADT*);
extern void Insert(struct arrayADT*);
extern void InsertNice(struct arrayADT*);
extern void Delete(struct arrayADT*);
extern int LinearSearch(struct arrayADT*);
extern int LinearSearchWithShift(struct arrayADT*);
extern int BinarySearch(struct arrayADT*);
extern void BubbleSort(struct arrayADT*);