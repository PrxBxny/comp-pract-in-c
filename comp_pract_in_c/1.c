#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int maximum(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int num1, num2, num3;
	printf("Введите 3 числа через пробел:\n");
	if (scanf("%d %d %d", &num1, &num2, &num3) != 3) {
		printf("Ошибка ввода чисел!\n");
		return 1;
	}

	int MAX = maximum(maximum(num1, num2), num3);
	int nod = 1; // наименьший общий делитель

	for (int i = 2; i <= MAX; i++)
	{
		if ((num1 % i == 0) && (num2 % i == 0) && (num3 % i == 0))
		{
			nod = i;
			break;
		}
	}
	printf("Наименьший общий делитель чисел: %d, %d, %d = %d", num1, num2, num3, nod);

	return 0;
}