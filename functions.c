#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * handle_negative - Manages negative numbers.
 * @num: The number to check.
 * @buffer: The buffer to store the negative sign.
 * @len: The length counter.
 * 
 * Description: This function checks if a number is negative.
 *              If so, it adds a '-' sign to the buffer and
 *              returns the absolute value of the number.
 * 
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
 * 
 * Description: This function calculates the number of digits
 *              in an integer.
 * 
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
 * 
 * Description: This function converts an integer into a 
 *              string and stores the result in the provided 
 *              buffer.
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
