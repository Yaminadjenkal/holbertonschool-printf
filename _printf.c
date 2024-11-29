#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * handle_negative - Manages negative numbers.
 * @num: The number to check.
 * @buffer: The buffer to store the negative sign.
 * @len: The length counter
 * Description: This function checks if a number is negative.
 *If so, it adds a '-' sign to the buffer and
 * returns the absolute value of the number.
 * Return: The absolute value of the number.
 */
int handle_negative(int num, char *buffer, int *len)
{
	if (num < 0)
	{
		buffer[(*len)++] = '-';
		return (-num);
	}
	return (num);
}

/**
 * calculate_length - Calculates the length of the number.
 * @num: The number to measure.
 * Description: This function calculates the number of digits
 * in an integer.
 * Return: The length of the number.
 */
int calculate_length(int num)
{
	int len = 0;

	do {
		len++;
		num /= 10;
	} while (num != 0);

	return (len);
}

/**
 * convert_to_string - Converts a number to a string.
 * @num: The number to convert.
 * @buffer: The buffer to store the string.
 * @len: The length of the number.
 * Description: This function converts an integer in a
 *string and stores the result in the provided
 *buffer.
 */
void convert_to_string(int num, char *buffer, int len)
{
	buffer[len] = '\0';

	while (num != 0)
	{
		buffer[--len] = (num % 10) + '0';
		num /= 10;
	}

	if (len == 1)
	{
		buffer[0] = '0';
	}
}

/**
 * print_d - Function to handle the %d specifier
 * @args: A va_list containing the integer to print
 * Description: This function retrieves an integer from the va_list
 * and prints it. It handles negative numbers by adding
 *a minus sign and converts the integer to a string for
 * printing.
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

/**
 * print_i - Function to handle the %i specifier.
 * @args: A va_list containing the integer to print
 * Description: This function retrieves an integer from the va_list
 *and prints it. It handles negative numbers by adding
 *a minus sign and converts the integer to a string for
 * printing.
 * Return: The number of characters printed.
 */
int print_i(va_list args)
{
	return (print_d(args));
}
