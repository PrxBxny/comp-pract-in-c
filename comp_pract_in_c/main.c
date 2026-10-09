#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "loader.h"

#define SIZE_ARR 76
#define ROWS 5
#define COLS 6


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int choice;
    do
    {
        printf("\n--- меню ---\n");
        printf("1 - Работа с массивом размера %d\n", SIZE_ARR);
        printf("2 - Работа с матрицей размера %dx%d\n", ROWS, COLS);
        printf("0 - Выход\n");
        printf("Выберите пункт: ");

        while (scanf("%d", &choice) != 1)
        {
            printf("Ошибка ввода, попробуйте снова...\n");
            while (getchar() != '\n');
        }

        switch (choice)
        {
        case 0:
            break;
        case 1:
            RunArray("libarray.dll");
            break;
        case 2:
            RunMatrix("libmatrix.dll");
            break;
        default:
            printf("Такого пункта нет\n");
        }
    } while (choice != 0);

    return 0;
}