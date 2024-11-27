#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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
	int temp;
	int count;
	int i;

	if (num < 0)
	{
		buffer[len++] = '-';
		num = -num;
	}

	temp = num;
	do
		len++;
	{
		while (temp != 0);

		temp /= 10;
	}
	buffer[len] = '\0';

	while (num != 0)
	{
		buffer[--len] = (num % 10) + '0';
		num /= 10;
	}

	count = 0;
	for (i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
