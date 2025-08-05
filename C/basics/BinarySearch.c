#include <stdio.h>


int binary_search(int search, int where[], int size, int *iterations);
int linear_search(int search, int where[], int size, int *iterations);

int main()
{
    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int B[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; 
    int C[30] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 }; 

    int numberOfIterations = 0;

    int retval = binary_search(10, A, 10, &numberOfIterations);
    printf("Binary search searched for element %d in %d iterations\n", A[retval], numberOfIterations);
    retval = linear_search(10, A, 10, &numberOfIterations);
    printf("Linear search searched for element %d in %d iterations\n", A[retval], numberOfIterations);

    retval = binary_search(20, B, 20, &numberOfIterations);
    printf("Binary search searched for element %d in %d iterations\n", B[retval], numberOfIterations);
    retval = linear_search(20, B, 20, &numberOfIterations);
    printf("Linear search searched for element %d in %d iterations\n", B[retval], numberOfIterations);

    retval = binary_search(30, C, 30, &numberOfIterations);
    printf("Binary search searched for element %d in %d iterations\n", C[retval], numberOfIterations);
    retval = linear_search(30, C, 30, &numberOfIterations);
    printf("Linear search searched for element %d in %d iterations\n", C[retval], numberOfIterations);

}


int binary_search(int value, int input[], int size, int *iterations)
{
    *iterations = 0;
    int high,mid,low;
    //Inital low
    low = 0;
    //Initial high
    high = size - 1;
   
    
    while(low <= high)
    {
        *iterations = *iterations + 1;
        mid = (low + high) / 2;
        
        if(value == input[mid])
            return mid;

        if(value < input[mid])
            high = mid - 1;

        if(value > input[mid])
            low = mid + 1;
        
    }
   
    return -1;

}

int linear_search(int value, int input[], int size, int *iterations)
{
    *iterations = 0;
    for(int i = 0; i < size; i++)
    {

        *iterations = *iterations + 1;
        if(input[i] == value)
            return i;
    }

    return -1;
}