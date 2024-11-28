#include "main.h"
#include <unistd.h>

/**
 * print_integer - Function that prints an integer
 * @args: Argument list containing the integer to be printed
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
    int n = va_arg(args, int);
    char buffer[50];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    if (n < 0)
    {
        buffer[i++] = '-';
        n = -n;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
        count += write(1, &buffer[j], 1);

    return count;
}

