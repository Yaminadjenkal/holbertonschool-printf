#include "holberton.h"

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

