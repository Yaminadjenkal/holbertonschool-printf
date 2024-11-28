#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	print_type types[] =
	{
		{"c", print_char},
		{"i", print_integer},
		{"d", print_decimal},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				count += write(1, "%%", 2);
			}
			else
			{
				int j = 0;
				while (types[j].format != NULL)
				{
					if (types[j].format[0] == format[i])
					{
						count += types[j].func(args);
						break;
					}
					j++;
				}

				if (types[j].format == NULL)
				{
					count += write(1, &format[i - 1], 2);
				}
			}
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
