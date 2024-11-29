#include "main.h"
#include <stdarg.h>

/**
 * print_i - Function to handle the %i specifier.
 * @args: A va_list containing the integer to print.
 * 
 * Description: This function retrieves an integer from the va_list
 *              and prints it. It handles negative numbers by adding
 *              a minus sign and converts the integer to a string for
 *              printing.
 * 
 * Return: The number of characters printed.
 */
int print_i(va_list args)
{
    return print_d(args);
}
