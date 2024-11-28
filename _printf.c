#include "main.h"
#include <stdarg.h>
typedef struct print_type 
{
    char *format;
    int (*func)(va_list);
} 
print_type;
int print_char(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_string(va_list args);

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
        {NULL, NULL}
    };

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
	{
            i++;
            int j = 0;
            while (types[j].format != NULL) {
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
        } else
	{
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (count);
}
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}

int print_integer(va_list args) 
{
    int num = va_arg(args, int);

