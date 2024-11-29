#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    const char *p = format;

    va_start(args, format);

    while (*p)
    {
        if (*p == '%')
        {
            p++;
            switch (*p)
            {
            case 'c':
                printed_chars += _putchar(va_arg(args, int));
                break;
            case 's':
                printed_chars += _puts(va_arg(args, char *));
                break;
            case '%':
                printed_chars += _putchar('%');
                break;
            case 'd':
            case 'i':
                printed_chars += print_number(va_arg(args, int));
                break;
            case 'u':
                printed_chars += print_unsigned(va_arg(args, unsigned int));
                break;
            case 'o':
                printed_chars += print_octal(va_arg(args, unsigned int));
                break;
            case 'x':
                printed_chars += print_hex(va_arg(args, unsigned int), 0);
                break;
            case 'X':
                printed_chars += print_hex(va_arg(args, unsigned int), 1);
                break;
            case 'p':
                printed_chars += print_pointer(va_arg(args, void *));
                break;
            default:
                printed_chars += _putchar('%') + _putchar(*p);
                break;
            }
        }
        else
        {
            printed_chars += _putchar(*p);
        }
        p++;
    }

    va_end(args);
    return printed_chars;
}

