#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Ru");

	int num1, num2, num3;
	printf("¬ведите 3 числа через пробел:\n");
	scanf("%d %d %d", &num1, &num2, &num3);

	int maximum = max(max(num1, num2), num3);
	int nod = 1; // наименьший общий делитель

	for (int i = 2; i < maximum; i++)
	{
		if ((num1 % i == 0) && (num2 % i == 0) && (num3 % i == 0))
		{
			nod = i;
			break;
		}
	}
	printf("Ќаименьший общий делитель чисел: %d, %d, %d = %d", num1, num2, num3, nod);

	return 0;
}