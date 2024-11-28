#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int handle_negative(int num, char *buffer, int *len)
{
	if (num < 0)
	{
		buffer[(*len)++] = '-';
		return (-num);
	}
	return (num);
}

int calculate_length(int num)
{
	int len = 0;

	do {
		len++;
		num /= 10;
	} while (num != 0);

	return (len);
}

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

int print_i(va_list args)
{
	return print_d(args);
}
