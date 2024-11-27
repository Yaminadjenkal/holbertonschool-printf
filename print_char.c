#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/*
 * File: print_char.c
 */

/**
 * _printf - Custom implementation of the printf function for formatted output.
 * @format: A null-terminated string that specifies the format of the output.
 */


int _printf(const char *format, ...)

{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char value = (char)va_arg(args, int);
				putchar(value);
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
	
	return(0);
}

