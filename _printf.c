#include "main.h"
#include <stdarg.h>
#include <unistd.h>

typedef struct print_type 
{
	char *format;
	int (*func)(va_list);
} print_type;

int print_char(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_string(va_list args);

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

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return write(1, &c, 1);
}

int print_integer(va_list args) 
{
	int num = va_arg(args, int);
	char buffer[20];
	int len = 0;

	if (num == 0) {
		buffer[len++] = '0';
	} else {
		int temp = num;
		if (num < 0)
		{
			buffer[len++] = '-';
			temp = -temp;
		}
		int i = len;
		while (temp > 0) {
			buffer[i++] = (temp % 10) + '0';
			temp /= 10;
		}
		for (int i = len, j = i + len - 1; i < j; i++, j--) 
		{
			char temp_char = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp_char;
		}
		len = i;
	}
	return write(1, buffer, len);
}

int print_decimal(va_list args) 
{
	return print_integer(args);
}

int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (*str) {
		count += write(1, str++, 1);
	}
	return (count);
}

