#include "main.h"

/**
 * print_string - Prints a string.
 * @args: The argument list.
 * @buffer: The buffer to store the string.
 * @buffer_index: The index in the buffer to start storing the string.
 * 
 * Return: The number of characters printed.
 */
int print_string(va_list args, char *buffer, int *buffer_index)
{
    const char *str = va_arg(args, const char *);
    int len = 0;

    while (*str)
    {
        buffer[(*buffer_index)++] = *str++;
        len++;
    }

    return len;
}
