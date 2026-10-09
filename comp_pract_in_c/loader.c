#include "loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define SIZE_ARR 76
#define ROWS 5
#define COLS 6

void RunArray(const char* libname)
{
    // HINSTANCE lib — переменная, в которую сохраняется дескриптор(уникальный ID или адрес начала библиотеки в памяти), LoadLibrary - функция Windows API
    HINSTANCE lib = LoadLibrary(libname);
    if (!lib)
    {
        printf("cannot open library '%s'\n", libname);
        return;
    }

    // GetProcAddress(lib, "fillArrRandom") — ф-ия Windows API, которая заглядывает внутрь загруженной DLL, ищет там функцию по её текстовому имени и возвращает её точный адрес в оперативной памяти.
    void (*fill)(int*, int, int, int) = (void (*)(int*, int, int, int))  GetProcAddress(lib, "fillArrRandom");
    void (*print)(int*, int) = (void (*)(int*, int))           GetProcAddress(lib, "printArr");
    void (*process)(int*, int) = (void  (*)(int*, int))           GetProcAddress(lib, "processArr");

    if (!fill || !print || !process)
    {
        printf("cannot load functions from '%s'\n", libname);
        FreeLibrary(lib);
        return;
    }

    int* arr = (int*)malloc(SIZE_ARR * sizeof(int));
    fill(arr, SIZE_ARR, -50, 50);

    printf("\nИсходный массив (размер %d):\n", SIZE_ARR);
    print(arr, SIZE_ARR);

    printf("Массив после замены кратных 3 на 1:\n");
    print(arr, SIZE_ARR);

    free(arr);
    FreeLibrary(lib);
}

void RunMatrix(const char* libname)
{
    HINSTANCE lib = LoadLibrary(libname);
    if (!lib)
    {
        printf("cannot open library '%s'\n", libname);
        return;
    }

    void (*fill)(int*, int, int, int, int) = (void (*)(int*, int, int, int, int)) GetProcAddress(lib, "fillMatrixRandom");
    void (*print)(int*, int, int) = (void (*)(int*, int, int))          GetProcAddress(lib, "printMatrix");
    void (*process)(int*, int, int) = (void  (*)(int*, int, int))          GetProcAddress(lib, "processMatrix");

    if (!fill || !print || !process)
    {
        printf("cannot load functions from '%s'\n", libname);
        FreeLibrary(lib);
        return;
    }

    int* matrix = (int*)malloc(ROWS * COLS * sizeof(int));
    fill(matrix, ROWS, COLS, -50, 50);

    printf("\nИсходная матрица %dx%d:\n", ROWS, COLS);
    print(matrix, ROWS, COLS);

    printf("Матрица после замены кратных 3 на 1:\n");
    print(matrix, ROWS, COLS);

    free(matrix);
    FreeLibrary(lib);
}