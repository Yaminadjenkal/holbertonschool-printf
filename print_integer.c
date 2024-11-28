#include "main.h"

int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    char buffer[20];
    int i = 0;

    if (num == 0)
    {
        return _putchar('0');
    }

    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        count += _putchar(buffer[j]);
    }

    return count;
}

