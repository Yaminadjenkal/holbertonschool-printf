#include "main.h"

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (str[count])
    {
        _putchar(str[count]);
        count++;
    }
    return count;
}

