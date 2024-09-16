#define MAX_ROW 4
#define MAX_COL 4
#include <stdio.h>
#include <stdlib.h>
int main() {

   
    int A[MAX_ROW][MAX_COL];

    
    for(int r = 0; r < MAX_ROW; ++r) {
        for(int c = 0; c < MAX_COL; ++c) {
            A[r][c] = (r + 1) * (10 * (c + 1));
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }


}