#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};
	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			if (pfunc)
			{
				count += pfunc(arguments, &flags);
			}
			else if (*p == 'r')
			{
				count += print_reverse(arguments);
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*p);
			}
		}
		else
		{
			count += _putchar(*p);
		}
	}
	va_end(arguments);
	return (count);
}
