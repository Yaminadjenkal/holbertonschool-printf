#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_d - Function to handle the %d specifier.
 * @args: A va_list containing the integer to print.
 * Return: The number of characters printed.
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[50];
	int len = 0;

	if (num < 0)
	{
		buffer[len++] = '-';
		num = -num;
	}

	int temp = num;

	do
		len++;
	{	temp /= 10;
	} while (temp != 0);

	buffer[len] = '\0';

	while (num != 0)
	{
		buffer[--len] = (num % 10) + '0';
		num /= 10;
	}

	int count = 0;

	for (int i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
