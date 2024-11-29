#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_format_function - Selects the correct function to perform the operation.
 * @c2: The format specifier.
 * 
 * Return: A pointer to the function that corresponds to the specifier.
 */
int (*get_format_function(char c2))(va_list)
{
    print_type ftypes[] = {
        {"c", print_char},
        {"s", print_string},
        {"d", print_d},
        {"i", print_i},
        {"%", print_modulo},
        {"r", print_reverse},
        {NULL, NULL}
    };

    int ii = 0;

    while (ftypes[ii].format)
    {
        if (ftypes[ii].format[0] == c2)
            return ftypes[ii].func;
        ii++;
    }

    return NULL;
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing the format specifiers.
 * 
 * Description: This function mimics the standard printf function.
 *              It handles conversion specifiers such as %c, %s, %d, %i, %, and %r.
 * 
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;
    int (*f)(va_list);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            f = get_format_function(format[i]);
            if (f)
            {
                count += f(args);
            }
            else
            {
                count += write(1, &format[i - 1], 2);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (count);
}
