#include "libmatrix.h"
#include <stdio.h>
#include <stdlib.h>


void printMatrix(int* matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i * cols + j]);
        printf("\n");
    }
    printf("\n");
}

void fillMatrixRandom(int* matrix, int rows, int cols, int min, int max)
{
    for (int i = 0; i < rows * cols; i++)
        matrix[i] = rand() % (max - min + 1) + min;
}   

void processMatrix(int* matrix, int rows, int cols)
{
    for (int i = 0; i < rows * cols; i++)
        if (matrix[i] % 3 == 0)
            matrix[i] = 1;
}