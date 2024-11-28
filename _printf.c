#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Function that prints a character
 * @args: Argument list containing the character to be printed
 * Return: The number of characters printed (1)
 */
int print_char(va_list args)
{
	return (write(1, &va_arg(args, int), 1));
}

/**
 * print_string - Function that prints a string
 * @args: Argument list containing the string to be printed
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (str && str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

/**
 * _printf - Main function that implements a subset of printf functionality
 * @format: The format string containing format specifiers
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;

	print_type types[] = {{"c", print_char}, {"s", print_string}, {NULL, NULL}};

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			int j = 0;

			while (types[j].format)
			{
				if (types[j].format[0] == format[i])
				{
					count += types[j].func(args);
					break;
				}
				j++;
			}
			if (!types[j].format)
				count += write(1, &format[i - 1], 2);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
