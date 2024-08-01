#include <stdio.h>
#include <stdlib.h>

int main() {
    
    void *p = malloc(sizeof(int));

    int *pInt = (int*)p;

    *pInt = 10;

    printf("%d\n", *pInt);

    free(p);

    printf("%d\n", *pInt);

    *pInt = 20;

    printf("%d\n", *pInt);


}