#include <stdio.h>
#include <stdlib.h>

//Array structure
struct Array 
{
    int A[20];
    int size;
    int length;
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
    //2nd & 3rd struct members are ints, size and length 
    struct Array arr = {{10,20,30,40}, 20, 4};
    

    //Call "methods"
    printf("\nDisplay()\n");
    Display(&arr);
    printf("----------------------------\n");
    printf("\nGet()\n");
    Get(&arr);
    printf("----------------------------\n");
    printf("\nLength()\n");
    Length(&arr);
    printf("----------------------------\n");
    printf("\nAppend()\n");
    Append(&arr);
    printf("----------------------------\n");
    printf("\nLength()\n");
    Length(&arr);
    printf("-----------------------------\n");
    printf("\nSwap()\n");
    Swap(&arr);
    printf("-----------------------------\n");
    printf("\nGet()\n");
    Get(&arr);


    return 0;

}

//Definitions of operations supported by an Array 
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

void Display(struct Array *arr) {
    for(int i = 0; i < arr->length; ++i) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

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

void Length(struct Array *arr) {
    printf("%d\n",arr->length);
}

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

void Insert(struct Array *arr) {
    int __index;
    int __value;
    printf("Enter value ");
    scanf("%d", &__value);
    printf("\nEnter index ");
    scanf("%d", &__index);
    
    if(__index >= arr->size) {
        printf("\nIndex out of bounds\n");
    } else if (__index >= arr->length) {
        //We're inserting at the free slot
        arr->A[__index] = __value;
    }
}