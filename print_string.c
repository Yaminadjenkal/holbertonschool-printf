#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - Prints a string and updates a character counter.
 * @str: Pointer to the string to be printed.
 * @count: Pointer to the counter to update.
 *
 * Return: None.
 */

void print_string(const char *str, int *count)
{
	if (str)
	{
		while (*str)
		{
			putchar(*str);
			str++;
			(*count)++;
		}
	}
}


/**
 * print_invalid_format - Prints '%' and an invalid specifier.
 * @specifier: The invalid format specifier to print.
 * @count: Pointer to the printed character count.
 */


void print_invalid_format(char specifier, int *count)
{
	putchar('%');
	(*count)++;
	if (specifier)
	{
		putchar(specifier);
		(*count)++;
	}
}


/**
 * _printf_string - Prints formatted strings.
 * @format: Format string with %s specifier support.
 *
 * Description: Prints strings for %s and regular characters.
 *              Handles unsupported specifiers separately.
 *
 * Return: Total characters printed.
 */

int _printf_string(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				char *str = va_arg(args, char *);

				print_string(str, &count);
			}
			else
			{
				print_invalid_format(*format, &count);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

