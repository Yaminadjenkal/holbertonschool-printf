#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

int print_char(va_list args)
{
    char c = va_arg(args, int);
    return _putchar(c);
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (str[count])
    {
        _putchar(str[count]);
        count++;
    }
    return count;
}

int print_percent(va_list args)
{
    (void)args;
    return _putchar('%');
}

int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    char buffer[20];
    int i = 0;

    if (num == 0)
    {
        return _putchar('0');
    }

    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        count += _putchar(buffer[j]);
    }

    return count;
}

typedef struct format_specifier
{
    char specifier;
    int (*func)(va_list args);
} format_specifier;

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    format_specifier specs[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_integer},
        {'d', print_integer},
    };

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            int found = 0;

            for (int j = 0; j < 5; j++)
            {
                if (format[i] == specs[j].specifier)
                {
                    count += specs[j].func(args);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}

int main(void)
{
    int count;

    count = _printf("Hello %s! Your grade is %c.\n", "Alice", 'A');
    _putchar('\n');
    count = _printf("This is a percentage: %%\n");
    _putchar('\n');
    count = _printf("Number: %i\n", 12345);
    _putchar('\n');
    count = _printf("Negative Number: %d\n", -6789);
    _putchar('\n');

    return 0;
}
