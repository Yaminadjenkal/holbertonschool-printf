#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_d - Function to handle the %d specifier.
 * @args: A va_list containing the integer to print.
 * 
 * Description: This function retrieves an integer from the va_list
 *              and prints it. It handles negative numbers by adding
 *              a minus sign and converts the integer to a string for
 *              printing.
 * 
 * Return: The number of characters printed.
 */
int print_d(va_list args)
{
    int num = va_arg(args, int);
    char buffer[50];
    int len = 0;
    int count;
    int i;

    num = handle_negative(num, buffer, &len);
    len += calculate_length(num);
    convert_to_string(num, buffer, len);

    count = 0;

    for (i = 0; buffer[i] != '\0'; i++)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}

