#include "arr_processing.h"

int* withoutDuplicates(int* arr, int size, int* newSize)
{
    int* newArr = (int*)malloc(size * sizeof(int));
    if (newArr == NULL)
        return NULL;

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        int curNum = arr[i];
        bool isDuplicate = false;

        for (int j = 0; j < count; j++)
        {
            if (curNum == newArr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate)
            continue;

        newArr[count] = curNum;
        count++;
    }

    *newSize = count;

    return newArr;
}

int sumNegativMultipleOfFour(int* arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        if ((arr[i] < 0) && (arr[i] % 4 == 0))
            sum += arr[i];
    }

    return sum;
}