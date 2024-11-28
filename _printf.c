#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    print_type types[] = 
    {
        {"c", print_char},
        {"i", print_integer},
        {"d", print_decimal},
        {"s", print_string},
        {"r", print_reverse},  // Ajout d'un cas pour %r
        {NULL, NULL}
    };

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            int j = 0;
            while (types[j].format != NULL) 
            {
                if (types[j].format[0] == format[i])
                {
                    count += types[j].func(args);
                    break;
                }
                j++;
            }

            if (types[j].format == NULL)
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
    return count;
}

int print_reverse(va_list args)
{
    char *str = va_arg(args, char*);
    int len = 0;

    while (str[len] != '\0')
        len++;

    for (int i = len - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
    }
    return len;
}
