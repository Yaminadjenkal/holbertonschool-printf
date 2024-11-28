#include "main.h"
#include <unistd.h>
/**
 * print_integer - Function that prints an integer
 * @args: Argument list containing the integer to be printed
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	char buffer[20];
	int len = 0;
	int temp = num;
	int i, j, k;

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		if (num < 0)
		{
			buffer[len++] = '-';
			temp = -temp;
		}
		i = len;

		while (temp > 0)
		{
			buffer[i++] = (temp % 10) + '0';
			temp /= 10;
		}

		j = i - 1;

		for (k = len; k < j; k++, j--)
		{
			char tmp = buffer[k];

			buffer[k] = buffer[j];
			buffer[j] = tmp;
		}

		len = i;
	}

	return (write(1, buffer, len));
}
