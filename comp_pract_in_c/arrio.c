#include "arrio.h"

void input_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] = ", i);

		while (scanf("%d", &arr[i]) != 1)
		{
			printf("Input error!\n");

			// очищаем буфер от некорректных символов (букв, знаков), 
			while (getchar() != '\n');

			printf("arr[%d] = ", i); // повторяем запрос для текущего индекса
		}
	}
}

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}