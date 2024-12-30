#include "/home/vscode/git/DSA/C/Include/ArrayADT.h"
#include <stdio.h>
int main() {

    struct arrayADT myArray = {{1,2,3}, 15, 3};

    int index = LinearSearch(&myArray);

    if(index < 0) {
        printf("Value not found in the array\n");
    } else {
        printf("Value found at index %d\n", index);
    }

}