#include <stdio.h>
#include <malloc.h>
#include <linux/limits.h>

void* foo();
void fooFill(void*, const char, int);
int *bar();

int main() {

    //Allocate
    void *allocatedSpace = foo();

    //Populate the allocated area
    fooFill(allocatedSpace, 'X', 100);

   
    int *pStackFrameVariable = bar();

    printf("%d\n", *pStackFrameVariable);

    

}


//Allocate memory
void* foo() {
    void *p = malloc(PATH_MAX); // 4096 | one page

    return p;
}

//Fill the allocated memory
//This is perfectly ok, just don't forget to free the memory when done
//we don't want any leakage
void fooFill(void *_allocatedSpace, const char _c, int _size) {
    char *__pAllocatedSpace = (char*)_allocatedSpace;
    int __pos = 0;
    //Put the character into the buffer _size times
    while(++__pos <= _size) {
        *(__pAllocatedSpace + __pos) = _c;
    }

    *(__pAllocatedSpace + __pos + 1) = '\0';


}

//This produces warning.
//After the call, stack frame is "destroyed"
//If there is enough memory in the stack segment, then we should be ok
//eventho contents are volatile
int* bar() {
    int __localVariable = 123;

    return &__localVariable;

}