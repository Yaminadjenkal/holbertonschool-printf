#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int handle_specifier(char spec, va_list args)
{
    switch (spec)
    {
    case 'c':
        return print_char(args);
    case 's':
        return print_string(args);
    case 'd':
    case 'i':
        return print_decimal(args);
    case 'r':
        return print_reverse(args);
    case 'R':
        return print_rot13(args);
    default:
        return -1;
    }
}
