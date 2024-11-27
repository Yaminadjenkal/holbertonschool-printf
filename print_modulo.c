#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf_modulo - Custom implementation for printing modulos.
 * @format: A null-terminated string that specifies the format of the output.
 * Return: The number of characters printed excluding the null byte used
 */
int _printf_modulo(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
			}
			else
			{
				putchar('%');
				putchar(*format);
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (0);
}
