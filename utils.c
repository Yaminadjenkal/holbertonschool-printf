#include <unistd.h>
#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_number - prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int printed_chars = 0;
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		printed_chars++;
		num = -n;
	}

	if (num / 10)
	{
		printed_chars += print_number(num / 10);
	}

	_putchar((num % 10) + '0');
	printed_chars++;

	return (printed_chars);
}

/**
 * print_unsigned - prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int printed_chars = 0;

	if (n / 10)
	{
		printed_chars += print_unsigned(n / 10);
	}

	_putchar((n % 10) + '0');
	printed_chars++;

	return (printed_chars);
}

/**
 * print_octal - prints an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
	int printed_chars = 0;

	if (n / 8)
	{
		printed_chars += print_octal(n / 8);
	}

	_putchar((n % 8) + '0');
	printed_chars++;

	return (printed_chars);
}

/**
 * print_hex - prints an unsigned integer in hexadecimal format
 * @n: The unsigned integer to print
 * @uppercase: If non-zero, use uppercase letters
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	int printed_chars = 0;
	char *hex_digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
	{
		printed_chars += print_hex(n / 16, uppercase);
	}

	_putchar(hex_digits[n % 16]);
	printed_chars++;

	return (printed_chars);
}

/**
 * print_pointer - prints a pointer address
 * @ptr: The pointer to print
 *
 * Return: The number of characters printed
 */
int print_pointer(void *ptr)
{
	int printed_chars = 0;
	unsigned long addr = (unsigned long)ptr;

	printed_chars += _puts("0x");
	printed_chars += print_hex(addr, 0);

	return (printed_chars);
}

