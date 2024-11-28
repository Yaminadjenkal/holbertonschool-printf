#include "main.h"
#include <unistd.h>

/**
 * print_string - Function that prints a string
 * @args: Argument list containing the string to be printed
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;

    if (s == NULL)
        s = "(null)";  // Gérer les cas où la chaîne est NULL

    while (s[count])
    {
        count += write(1, &s[count], 1);
    }
    return count;
}

