/*************************************************************
 * ArrayADT abstract data type
 *Supports basic methods such as Display, Search, Sort etc
 ************************************************************/
#define SIZE 15
#define INSERT_NICE
#define LINEAR_SEARCH
#define LINEAR_SEARCH_WITH_SHIFT

//State enum
typedef enum ArrayADT_State
{
    UNSORTED,
    SORTED
} State;

typedef enum ArrayADT_Order
{
    ORDER_ASCENDING,
    ORDER_DESCENDING,
    ORDER_OTHER,
    ORDER_UNSORTED
} SortOrder;

typedef enum ArrayADT_Codes
{
    ARRAY_FULL,
} Codes;

//ArrayADT structure
struct ArrayADT
{
    State state;
    int capacity;   //Maximum number of elements stored
    int length;     //Current number of elements stored
    int A[SIZE];    //Fixed size of SIZE elements
    
};


//Prototypes of operations supported by an ArrayADT 
extern int Get(struct ArrayADT*, int);
extern void Append(struct ArrayADT*, int);
extern int Length(struct ArrayADT*);
extern int Swap(struct ArrayADT*, int, int);
extern int InsertAt(struct ArrayADT*, int, int);
extern int Insert(struct ArrayADT*, int);
extern int Delete(struct ArrayADT*, int);
extern int LinearSearch(struct ArrayADT*, int);
extern int LinearSearchWithShift(struct ArrayADT*, int);
extern int BinarySearch(struct ArrayADT*, int);
extern void BubbleSort(struct ArrayADT*);
extern void Reverse(struct ArrayADT*);  
extern int Set(struct ArrayADT*, int, int);
extern int SortedOrder(struct ArrayADT*);
extern double Median(struct ArrayADT*);
extern int Mode(struct ArrayADT*);
extern void _QuickSort(struct ArrayADT*);