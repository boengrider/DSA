#include <stdio.h>
#include <stdlib.h>

struct Array 
{
    int *A;
    int size;
    int length;
};

void Display(struct Array*);
void Get(struct Array*);
void Append(struct Array*);
void Length(struct Array*);

int main() {

    struct Array arr;
    int n,i;

    printf("Enter size of an array ");
    scanf("%d",&arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));
    arr.length = 0;

    //Initialize array
    printf("How many elements to insert ? Maximum is %d\n", arr.size);
    scanf("%d",&n);
    printf("Enter all %d elements\n",n);

    for(i=0; i<n; i++) {

        printf("Element at index %d ", i);
        scanf("%d", &arr.A[i]);
        arr.length++;

    }

  

    //Call "methods"
    Display(&arr);
    Get(&arr);
    Length(&arr);
    Append(&arr);
    Length(&arr);


    return 0;

}

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