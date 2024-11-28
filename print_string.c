#include "main.h"
/**
 * print_string - Function that prints a string
 * @args: Argument list containing the string to be printed
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (str && str[count])
	{
		count += write(1, &str[count], 1);
	}
	return (count);
}
