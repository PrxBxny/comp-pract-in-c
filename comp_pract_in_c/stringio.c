#include "stringio.h"
#include <stdio.h>


void input_string(char* str, int max_size)
{
	printf("¬ведите вашу строку: ");
	fgets(str, max_size, stdin);

	// убираем \n
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
}

void print_string(const char* str)
{
	printf("–езультат программы: %s\n", str);
}