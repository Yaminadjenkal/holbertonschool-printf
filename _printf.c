#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int print_modulo(va_list args)
{
	(void)args;
	return (write(1, "%%", 2));
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	int j;

	print_type types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_modulo},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;

			while (types[j].format)
			{
				if (types[j].format[0] == format[i])
				{
					count += types[j].func(args);
					break;
				}
				j++;
			}
			if (!types[j].format)
				count += write(1, &format[i - 1], 2);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

