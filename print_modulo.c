#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_modulo - Prints a percent sign.
 * @args: Argument list (unused).
 * 
 * Return: The number of characters printed.
 */
int print_modulo(va_list args)
{
    (void)args;
    return (write(1, "%%", 2));
}

