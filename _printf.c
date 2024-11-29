#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"

int handle_format(const char *format, va_list args);
int handle_specifier(char specifier, va_list args);

/**
 * _printf - Produces output according to a format
 * @format: A string containing the characters and the specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to 
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	printed_chars = handle_format(format, args);

	va_end(args);
	return (printed_chars);
}

/**
 * handle_format - Parses the format string and processes each specifier
 * @format: A string containing the characters and the specifiers
 * @args: A va_list containing the arguments to be printed
 *
 * Return: The number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int printed_chars = 0;
	const char *p = format;

	while (*p)
	{
		if (*p == '%')
		{
			p++;
			printed_chars += handle_specifier(*p, args);
		}
		else
		{
			printed_chars += _putchar(*p);
		}
		p++;
	}

	return (printed_chars);
}

/**
 * handle_specifier - Handles each specifier and prints the corresponding 
 * value
 * @specifier: The specifier character
 * @args: A va_list containing the arguments to be printed
 *
 * Return: The number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	int printed_chars = 0;

	switch (specifier)
	{
		case 'c':
			printed_chars += _putchar(va_arg(args, int));
			break;
		case 's':
			printed_chars += _puts(va_arg(args, char *));
			break;
		case '%':
			printed_chars += _putchar('%');
			break;
		case 'd':
		case 'i':
			printed_chars += print_number(va_arg(args, int));
			break;
		case 'u':
			printed_chars += print_unsigned(va_arg(args, unsigned int));
			break;
		case 'o':
			printed_chars += print_octal(va_arg(args, unsigned int));
			break;
		case 'x':
			printed_chars += print_hex(va_arg(args, unsigned int), 0);
			break;
		case 'X':
			printed_chars += print_hex(va_arg(args, unsigned int), 1);
			break;
		case 'p':
			printed_chars += print_pointer(va_arg(args, void *));
			break;
		default:
			printed_chars += _putchar('%');
			printed_chars += _putchar(specifier);
			break;
	}

	return (printed_chars);
}

