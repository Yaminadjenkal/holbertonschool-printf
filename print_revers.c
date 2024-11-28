#include <stdarg.h>
#include <unistd.h>

int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0, i;

	if (!str)
		str = "(null)";

	while (str[length])
		length++;

	for (i = length - 1; i >= 0; i--)
	{
		write(1, &str[i], 1);
	}

	return length;
}

