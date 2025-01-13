#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void seekEnd();

int main(int argc, char *argv[]) {
    
    FILE *input = fopen("/home/coach/Documents/GitHub/DSA/C/basics/File Handling/input.txt","r");

   

    fseek(input,0L,SEEK_SET);
   
    printf("%c ", fgetc(input));

    fseek(input,1L,SEEK_SET);
   
    printf("%c ", fgetc(input));

    
    
    
}


void seekEnd() {
    clock_t __start, __stop;
    double __duration;

    
    
    FILE *input = fopen("/home/coach/Documents/GitHub/DSA/C/basics/File Handling/input.txt","r");

    printf("Initial offset from FILE struct is %ld\n", input->_offset);

    __start = clock();
    fseek(input, 0L, SEEK_END);
    __stop = clock();
    //long fsize = ftell(input);
    //printf("Size of the file is %ld\n", fsize);

    printf("Size of the file from FILE struct is %ld ", input->_offset);
    printf("(%f seconds)", ((double)(__stop - __start)) / CLOCKS_PER_SEC);
}