#include "main.h"
/*
 * File: print_char.c
 *
 * Description: Implements the `print_char` function to print a character
 * from a variadic argument list.
 */

/**
 * print_char - Prints a character to standard output.
 * @args: The variadic argument list.
 * Return: 1 if successful, -1 on error.
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
