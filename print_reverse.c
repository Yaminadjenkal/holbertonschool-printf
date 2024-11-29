#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_reverse - Prints a string in reverse.
 * @args: Argument list containing the string to be reversed.
 * 
 * Return: The number of characters printed.
 */
int print_reverse(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0, i;

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    for (i = len - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
    }

    return (len);
}
