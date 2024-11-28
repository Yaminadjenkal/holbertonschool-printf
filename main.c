#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction printf personnalisée pour gérer les spécificateurs %d et %i.
 * @format: La chaîne de format.
 * 
 * Return: Le nombre de caractères imprimés.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;

    va_start(args, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'd')
            {
                count += print_d(args);
            }
            else if (*p == 'i')
            {
                count += print_i(args);
            }
        }
        else
        {
            write(1, p, 1);
            count++;
        }
    }

    va_end(args);
    return count;
}

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    printf("Length: %d\n", len);

    len = _printf("Number (%%d): %d\n", -12345);
    printf("Length: %d\n", len);

    len = _printf("Number (%%i): %i\n", 67890);
    printf("Length: %d\n", len);

    return (0);
}

