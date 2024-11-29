#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

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

int print_modulo(va_list args)
{
    (void)args;
    return (write(1, "%%", 2));
}

int (*get_format_function(char c2))(va_list)
{
    print_type ftypes[] = {
        {"c", print_char},
        {"s", print_string},
        {"d", print_d},
        {"i", print_i},
        {"%", print_modulo},
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
