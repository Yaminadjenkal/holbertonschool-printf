#include "main.h"
#include <unistd.h>

/**
 * print_char - Function that prints a character
 * @args: Argument list containing the character to be printed
 * Return: The number of characters printed (1)
 */
int print_char(va_list args)
{
    return (write(1, &va_arg(args, int), 1));
}

