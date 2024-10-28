#include <stdio.h>
#include <Array.h>
#define INSERT_NICE
#define LINEAR_SEARCH
#define LINEAR_SEARCH_WITH_SHIFT



int main() {

    //Init using initializer list
    //Len is set to 9, so we're leaving one free slot
    struct Array arr = {{10,20,30,40,50,60,70,80,90}, 10, 9};
    
    int index;
    while(1) {
        #ifdef LINEAR_SEARCH
            #ifdef LINEAR_SEARCH_WITH_SHIFT
                index = LinearSearchWithShift(&arr);
            #else
                index = LinearSearch(&arr);
            #endif
            printf("%d\n", index);
            Display(&arr);
        #else
            //Not yet implemented
        #endif
    } 

    return 0;

}