#include "main.h"
#include <unistd.h>

/**
 * print_char - Function that prints a character
 * @args: Argument list containing the character to be printed
 * Return: The number of characters printed (1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);  // va_arg renvoie un int, on peut directement l'assigner à un char
    return (write(1, &c, 1));    // Pas besoin de & sur va_arg
}

