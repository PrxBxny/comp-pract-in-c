#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arrio.h"
#include "arr_processing.h"

#define SIZE 25

int main()
{
    setlocale(LC_ALL, "ru");

    int arr[SIZE];
    input_arr(arr, SIZE);

    int actualNewSize = 0; // новый размер

    int* uniqueArr = withoutDuplicates(arr, SIZE, &actualNewSize);

    if (uniqueArr != NULL)
    {
        printf("исходный массив (размер %d):\n", SIZE);
        print_arr(arr, SIZE);

        printf("\n\nмассив без дубликатов (новый размер %d):\n", actualNewSize);
        print_arr(uniqueArr, actualNewSize);

        free(uniqueArr);
    }

    return 0;
}
