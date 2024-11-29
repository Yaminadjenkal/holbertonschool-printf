#include "main.h"

/**
 * print_char - Prints a character.
 * @args: The argument list.
 * @buffer: The buffer to store the character.
 * @buffer_index: The index in the buffer to store the character.
 * 
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args, char *buffer, int *buffer_index)
{
    char c = (char) va_arg(args, int);
    buffer[(*buffer_index)++] = c;
    return 1;
}

