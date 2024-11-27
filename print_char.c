#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/*
 * File: print_char.c
 */
<<<<<<< HEAD

=======
>>>>>>> 05f9000ecaa73ab9fed9dcd01ad07269327febff
/**
 * _printf - Custom implementation of the printf function for formatted output.
 * @format: A null-terminated string that specifies the format of the output.
 */
<<<<<<< HEAD
int _printf(const char *format, ...)
=======
void _printf(const char *format, ...)
>>>>>>> 05f9000ecaa73ab9fed9dcd01ad07269327febff
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
<<<<<<< HEAD
=======

>>>>>>> 05f9000ecaa73ab9fed9dcd01ad07269327febff
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
<<<<<<< HEAD

=======
>>>>>>> 05f9000ecaa73ab9fed9dcd01ad07269327febff
	va_end(args);
	return (0);
}

