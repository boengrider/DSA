#include <stdio.h>
#include <stdlib.h>

typedef struct Rectangle {
    int length;
    int height;
} rectangle;


int main() {
    
    //Declare and initialize Rectangle on the stack
    struct Rectangle r = { 10, 5 };

    //Declare and initialize a pointer to a Rectangle
    struct Rectangle *p = &r;

    printf("initial rectangle r { %d, %d }\n", r.length, r.height);

    //To access r we have 3 options

    // Option A
    *(int*)p = 100;
    *((int*)p+1) = 50;
    printf("Option A r { %d, %d }\n", r.length, r.height);
    
    // Option B
    (*p).length = 1000;
    (*p).height = 500;
    printf("Option B r { %d, %d }\n", r.length, r.height);
    
    // Option C
    p->length = 10000;
    p->height = 5000;
    printf("Option C r { %d, %d }\n", r.length, r.height);



    //Declare a void pointer
    void *pRectangle;

    //Initialize pointer. Allocate storage on the heap
    pRectangle = malloc(sizeof(rectangle));

    //Initialize a Rectangle on the heap
    ((rectangle*)pRectangle)->length = r.length;
    ((rectangle*)pRectangle)->height = r.height;

    printf("heap rectangle { %d, %d }\n", ((rectangle*)pRectangle)->length, ((rectangle*)pRectangle)->height);
    

      

}