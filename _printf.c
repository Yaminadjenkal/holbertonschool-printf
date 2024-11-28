#include <stdarg.h>
#include <unistd.h>
#include "main.h"

typedef struct set
{
	char spec;
	int (*print)(va_list list);
} set;

int _printf(const char *format, ...)
{
	int i, j, count = 0, find;
	va_list list;

	set arguments[] = {
		{'c', print_char},
		{'d', print_d},
		{'i', print_d},
		{'s', print_str},
		{'R', print_rot13},
		{'r', print_rev},
	};

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break;

			find = 0;

			for (j = 0; j < 6; j++)
			{
				if (format[i + 1] == arguments[j].spec)
				{
					count += arguments[j].print(list);
					find = 1;
					i++;
					break;
				}
			}

			if (!find)
			{
				if (format[i + 1] == '%')
				{
					count += write(1, "%", 1);
					i++;
				}
				else
					count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}

	va_end(list);
	return (count);
}
