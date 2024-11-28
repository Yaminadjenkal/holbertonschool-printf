#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Main function that implements a subset of printf functionality
 * @format: The format string containing format specifiers
 * Return: The total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count = 0, i = 0, j, find;
	print_type types[] = {
		{"c", print_char},
		{"d", print_decimal},
		{"i", print_integer},
		{"s", print_string},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;
			find = 0;

			for (j = 0; j < 4; j++)
			{
				if (format[i + 1] == types[j].format[0])
				{
					count += types[j].func(list);
					find = 1;
					i++;
					break;
				}
			}

			if (find == 0)
			{
				if (format[i + 1] == '%')
				{
					count += write(1, "%", 1);
					i++;
				}
				else
					count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}

	va_end(list);

	return (count);
}
