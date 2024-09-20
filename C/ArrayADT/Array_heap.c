#include <stdio.h>
#include <stdlib.h>

//Array structure
struct Array 
{
    int *A;
    int size;
    int length;
};

//Prototypes of operations supported by an Array 
void Display(struct Array*);
void Get(struct Array*);
void Append(struct Array*);
void Length(struct Array*);
void Swap(struct Array*);

int main() {

    struct Array arr;
    int n,i;

    printf("Enter size of an array ");
    scanf("%d",&arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));
    arr.length = 0;

    //Initialize array
    printf("How many elements to initialize ? Maximum is %d\n", arr.size);
    scanf("%d",&n);
    printf("Enter all %d elements\n",n);

    for(i=0; i<n; i++) {

        printf("Element at index %d ", i);
        scanf("%d", &arr.A[i]);
        arr.length++;

    }

  
    Swap(&arr);
    Get(&arr);
    return 0;
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
    printf("Enter a new value ");
    scanf("%d", &__value);
    printf("\nIndex at which the valu will be stored ");
    scanf("%d",&__index);
    if(__index >= arr->size || __index < 0) {
        printf("\nIndex out of bounds\n");
    } else { 
        arr->A[__index] = __value;
    }
}