#include "main.h"
/*
 * File: print_decimal.c
 *
 * Description: Defines a function to print decimal numbers.
 */

/**
 * print_decimal - Prints a decimal number.
 * @args: The variadic argument list.
 *
 * Return: The result of print_integer.
 */


int print_decimal(va_list args)
{
	return (print_integer(args));
}
