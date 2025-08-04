#include <stdio.h>

void _QuickSort(int p[], int len);
int main()
{
    int array[10] = { 2, 1, 9, 7, 5, 4, 10, 8, 9, 3};


    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }

    _QuickSort(array, 10);

     for(int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }

}

void _QuickSort(int p[], int len)
{
    int pivot = len - 1; // Pick the last element as a pivot
    int i = -1;
    int j = 0;
    int tmp;

    while(j < pivot) {
        if(p[j] < p[pivot]) {
            tmp = p[++i];
            p[i] = p[j];
            p[j] = tmp;
        }

        j++;
    }

    tmp = p[i+1];
    p[i+1] = p[pivot];
    p[pivot] = tmp;

}