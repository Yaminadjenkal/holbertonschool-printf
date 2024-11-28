#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_reverse - Function that prints a string in reverse order.
 * @args: Argument list containing the string to be printed.
 * 
 * Return: The number of characters printed.
 */
int print_reverse(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;
    int count = 0;

    if (!str)
        str = "(null)";

    while (str[len])
        len++;

    int i;
    for (i = len - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
        count++;
    }

    return (count);
}

/**
 * _printf - Main function that implements a subset of printf functionality.
 * @format: The format string containing format specifiers.
 * 
 * Return: The total number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;
    int j;

    print_type types[] =
    {
        {"c", print_char},
        {"s", print_string},
        {"r", print_reverse},
        {NULL, NULL}
    };

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            j = 0;
            while (types[j].format)
            {
                if (types[j].format[0] == format[i])
                {
                    count += types[j].func(args);
                    break;
                }
                j++;
            }
            if (!types[j].format) count += write(1, &format[i - 1], 2);
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return(count);
}
