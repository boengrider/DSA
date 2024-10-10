#include <stdio.h>

//Array structure
struct Array 
{
    int A[10];
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

int main() {

    //1st struct member is an array of ints
    //2nd & 3rd struct members are ints, size and length of an array
    //Len is set to 9, so we're leaving one free slot
    struct Array arr = {{10,20,30,40,50,60,70,80,90}, 10, 9};
    

    while(1) {
        Display(&arr);
        Insert(&arr);
        Display(&arr);
    }

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
 is not full, insert appends an
 element istead of inserting it
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
    
    if(__index >= arr->size) {
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