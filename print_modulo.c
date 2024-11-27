#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Function that prints formatted output with modulo
 *
 * @format: Types of arguments passed to function
 * Return: Number of characters printed
 */
int _printf_modulo(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			putchar('%');
			count++;
			format++;
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
