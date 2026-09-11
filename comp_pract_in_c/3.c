#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arrio.h"
#include "arr_processing.h"

#define SIZE 19

int main()
{
    setlocale(LC_ALL, "ru");

    printf("test\n");

    int arr[SIZE];
    input_arr(arr, SIZE);
    print_arr(arr, SIZE);

    int sum = sumNegativMultipleOfFour(arr, 19);

    printf("сумма отрицательных чисел делящихся на 4: %d\n", sum);

    return 0;
}
