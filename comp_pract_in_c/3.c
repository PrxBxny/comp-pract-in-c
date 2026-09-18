#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "stringio.h"


int main()
{
	setlocale(LC_ALL, "Ru");

	char str[99];
	input_string(str, 99);

	int length = strlen(str);
	int dots = 0, commas = 0, exclamations = 0, questions = 0, colons = 0;

	for (int i = 0; i < length; i++)
	{
		switch (str[i])
		{
			case '.': dots++; break;
			case ',': commas++; break;
			case '!': exclamations++; break;
			case '?': questions++; break;
			case ':': colons++; break;
			default:  break;
		}
	}

	print_string(str);

	printf("\nСтатистика знаков препинания:\n");
	printf("Точки (.): %d\n", dots);
	printf("Запятые (,): %d\n", commas);
	printf("Восклицательные знаки (!): %d\n", exclamations);
	printf("Вопросительные знаки (?): %d\n", questions);
	printf("Двоеточия (:): %d\n", colons);

	return 0;
}