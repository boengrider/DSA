// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int main() {
    short a = 255; // Data variable 
    short *pa;     // Adress variable (pointer)
    pa = &a;     // Initialize pointer with "address of" operator
    
    (*pa)++;   // Dereference pointer, and increment data stored at that location
    printf("%d\n", a); // Prints 256
    
  
    unsigned char *pc = (char*)pa; // Declare and initialize a pointer to char
                                   // Cast to char pointer from a short pointer
    pc++;
    
    printf("*pc = %p\n", pc); // Prints *pc = $SOME_ADDRESS on stack
    printf("%d\n", *pc);      // Prints, since the second byte is 0b10000000
    
    
    void *p = malloc(5 * sizeof(int)); // Allocate 5 ints worth of storage
    
    int *pi = (int*)p; // Cast void pointer returned by malloc to int pointer
    
    *pi = 10;         // Store 10 at the "1st" int loation  
    *(pi + 4) = 100;  // Store 100 at the "2nd" int location
    
    printf("Address of heap block %p\n", p); // Prints some address
    
    printf("%d\n", *(pi + 4));  // Prints 100
     
    free(p); // Free dynamically allocated memory
}