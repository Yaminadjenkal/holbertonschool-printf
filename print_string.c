#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_string - Prints a string.
 * @args: Argument list containing the string to be printed.
 * 
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    return (count);
}

