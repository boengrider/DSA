#include <stdlib.h>
#include <stdio.h>
#define PAGE_SIZE 4096

int main() {
    //Alloate less than page size
    void *p = malloc(100 * sizeof(char)); 

    /**
     * Minimum overhead per allocated chunk: 4 or 8 bytes
       Each malloced chunk has a hidden overhead of 4 bytes holding size
       and status information.

       glibc-2.2.5/malloc
     */

    char* pBoundary = (char*)p;

    int count = 1;
    while(1 > 0) {
      char item = *(pBoundary + (PAGE_SIZE * count));
      printf("%d\n", count);
      count++;
    }
}