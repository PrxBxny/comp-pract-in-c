#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void reverse_range(char* str, int start, int stop)
{
	while (start < stop)
	{
		char temp = str[start];
		str[start] = str[stop];
		str[stop] = temp;

		start++;
		stop--;
	}
}

void input_string(char* str, int max_size)
{
	printf("¬ведите вашу строку: ");
	fgets(str, max_size, stdin);

	// убираем /n
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

int main()
{
	setlocale(LC_ALL, "Ru");

	char str[99];
	input_string(str, 99);

	int length = strlen(str);
	reverse_range(str, 0, length - 1);

	for (int start = 0, end = 0; end <= length; end++)
	{
		if (str[end] == ' ' || str[end] == '\0')
		{
			reverse_range(str, start, end - 1);
			start = end + 1;
		}
	}

	print_string(str);

	return 0;
}