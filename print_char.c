#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a character.
 * @args: Argument list containing the character to be printed.
 * 
 * Return: The number of characters printed.
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}
