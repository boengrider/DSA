#include <stdio.h>
#define INSERT_NICE
#define SIZE 10

//Array structure
struct Array 
{
    int A[SIZE];//Fixed size of SIZE elements
    int size;   //Maximum number of elements stored
    int length; //Current number of elements stored
};

//Prototypes of operations supported by an Array 
void Display(struct Array*);
void Get(struct Array*);
void Append(struct Array*);
void Length(struct Array*);
void Swap(struct Array*);
void Insert(struct Array*);
void InsertNice(struct Array*);
void Delete(struct Array*);
int Search(struct Array*);


int main() {

    //Init using initializer list
    //Len is set to 9, so we're leaving one free slot
    struct Array arr = {{10,20,30,40,50,60,70,80,90}, 10, 9};
    

    /*
    while(1) {
        printf("Displaying array\n");
        Display(&arr);
        printf("Inserting element\n");
        #ifdef INSERT_NICE
            InsertNice(&arr);
        #else
            Insert(&arr);
        #endif
        printf("Displaying array\n");
        Display(&arr);
        printf("Deleteing element\n");
        Delete(&arr);
        printf("Displaying array\n");
        Display(&arr);
    }
    */


    int index = Search(&arr);
    printf("%d\n", index);

    return 0;

}


//===================================================
// Definitions of operations supported by Array ADT
//===================================================

/*********************************
 Get elemenent at specified index
*********************************/
void Get(struct Array *arr) {
    int __index;
    printf("Enter index of an element\n");
    scanf("%d", &__index);
    if(__index >= arr->size) {
        printf("Index %d is out of bounds\n", __index);
    } else {
        printf("%d\n", arr->A[__index]);
    }
}

/************************************
 Display current contents of an array
************************************/
void Display(struct Array *arr) {
    for(int i = 0; i < arr->length; ++i) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

/******************************
 Append to the end of an array, 
 given it's not full. If the array
 is not full.
*******************************/
void Append(struct Array *arr) {
    int __value;
    if(arr->length < arr->size) {
        printf("Enter a new value ");
        scanf("%d",&__value);
        arr->A[++arr->length] = __value;
    } else {
        printf("Array is full\n");
    }
}

/*********************************
 Get length i.e current number of 
 elements stored in an array
*********************************/
void Length(struct Array *arr) {
    printf("%d\n",arr->length);
}

/*********************************
 Swap two elements within an array
**********************************/
void Swap(struct Array *arr) {
    int __index;
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nIndex at which the value will be stored ");
    scanf("%d",&__index);
    if(__index >= arr->size || __index < 0) {
        printf("\nIndex out of bounds\n");
    } else { 
        arr->A[__index] = __value;
    }
}

/*******************************************
 Insert element at the specified index.
 Move elements to the right by one position,
 poping the last element out 
 *******************************************/
void Insert(struct Array *arr) {
    int __index;
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nEnter index ");
    scanf("%d", &__index);
    
    if(__index >= arr->size || __index < 0)  {
        //Index is beyond array boundaries
        printf("\nIndex out of bounds\n");
    } else if(arr->length < arr->size) {
        printf("Appending\n");
        //Insert element at the last available position
        arr->A[arr->length] = __value;
        arr->length++;
    } else {
        if(__index == arr->length - 1) {
            //Simply insert at the very end
            arr->A[__index] = __value;
        } else {
            //We have some shifting to do
            int __stlIndex = arr->length - 2; //second to last index

            //Keep shifting until we arrive at the requested index
            while(__stlIndex >= __index) {
                arr->A[__stlIndex + 1] = arr->A[__stlIndex];
                __stlIndex--;
            }
            arr->A[__index] = __value;
        }
    }
}

/*************************************
 Insert element at the specified index
 Nicer version
 No appending. Simply insert at the 
 requested index. Only check if it's 
 not beyong the array boundaries
 *************************************/
void InsertNice(struct Array *arr) {
    int __index, __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nEnter index ");
    scanf("%d", &__index);

    if(__index >= arr->size || __index < 0) {
        printf("\nIndex out of bounds\n");
    } else {
        for(int i = arr->length - 1; i > __index; i--) {
            arr->A[i] = arr->A[i-1];
        }

        arr->A[__index] = __value;
    }

    //Only increase size if the wasn't full before inserting
    if(arr->length < arr->size) 
        arr->length++;
}

/***************************************
 Delete element at the specified index
 and shift all the elements to the right
 one position to the left
 ***************************************/
void Delete(struct Array *arr) {
    int __index;
    printf("\nEnter index ");
    scanf("%d", &__index);

    if(__index > arr->size || __index < 0) {
        printf("\nIndex out of bound\n");
    } else {
        for(int i = __index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i+1];
        }

        if(arr->length > 0)
            arr->length--;
    }
}

/***************************************
 * Linear search 
****************************************/
int Search(struct Array *arr) {
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);

    for(int i = 0; i < arr->length; i++) {
        if(__value == arr->A[i])
            //found
            return i;
    }

    //not found
    return -1;
}

