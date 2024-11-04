#include <Array.h>
#include <stdio.h>
  

int main() {
    struct Array arr = {{3,2,1,6,4,5,7,0,12,13,15,8,9,10}, 15, 15};
    printf("Unsorted array\n");
    Display(&arr);
    printf("Sorted array\n");
    BubbleSort(&arr);
    Display(&arr);
}