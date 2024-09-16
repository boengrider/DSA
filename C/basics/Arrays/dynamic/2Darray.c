#define MAX_ROW 4
#define MAX_COL 4
#include <stdio.h>
#include <stdlib.h>

int scale(int);

int main() {

   
    //Array of pointers to integers
    //Pointer 8 bytes * 4 total 32 bytes
    int *B[MAX_ROW];

    //For each row allocate space to store 4 integers (4*8) i.e columns
    for(int r = 0; r < MAX_ROW; ++r) {
        B[r] = (int*)malloc(MAX_COL * sizeof(int));

    }




    
    //Initialize matrix
    for(int r = 0; r < MAX_ROW; ++r) {
        for(int c = 0; c < MAX_COL; ++c) {
            int scaleFactor = scale(r);
            *(B[r] + c) = (c + 1) * scaleFactor;
        }
    }

   

    for(int r = 0; r < MAX_ROW; ++r) {
        printf("Row %d (%p)\n", r + 1, B[r]);
        for(int c = 0; c < MAX_COL; ++c) {
            printf("Column %d -> %d\n",(c + 1), *(B[r] + c));
        }
        printf("\n");
    }
    




}


int scale(int exponent) {
    if(exponent == 0) {
        return 1;
    } else if(exponent == 1) {
        return 10;
    }


    int result = 10;      
    for(int i = 2; i <= exponent; ++i) {
        result = result * 10;
    }

    return result;
}