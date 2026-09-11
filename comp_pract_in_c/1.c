#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool is_same(int num) /* если к сумме цифр этого числа прибавить квадрат этой суммы, то получится это же число */
{
    if (num < 10 || num >= 100)
        return false; /* не подходит по условию */

    int first_num = num / 10;
    int second_num = num % 10;
    int sum = first_num + second_num;

    if (num == first_num + second_num + (sum * sum))
        return true;

    return false;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        if (is_same(i))
            printf("%d\n", i);
    }
    
    return 0;
}
