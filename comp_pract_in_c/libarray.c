#include "libarray.h"
#include <stdio.h>
#include <stdlib.h>


void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillArrRandom(int* arr, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (max - min + 1) + min;
}

void processArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] % 3 == 0)
            arr[i] = 1;
}