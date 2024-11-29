#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buffer_index = 0;
    int len = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    int num_len;
                    num = handle_negative(num, buffer, &buffer_index);
                    num_len = calculate_length(num);
                    convert_to_string(num, buffer + buffer_index, num_len);
                    buffer_index += num_len;
                    len += num_len + (num < 0 ? 1 : 0);
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str)
                    {
                        buffer[buffer_index++] = *str++;
                        len++;
                    }
                    break;
                }
                case 'c': {
                    char c = (char) va_arg(args, int);
                    buffer[buffer_index++] = c;
                    len++;
                    break;
                }
                case '%': {
                    buffer[buffer_index++] = '%';
                    len++;
                    break;
                }
                default:
                    buffer[buffer_index++] = '%';
                    buffer[buffer_index++] = *format;
                    len += 2;
                    break;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
            len++;
        }
        format++;
    }

    va_end(args);
    buffer[buffer_index] = '\0';
    write(1, buffer, len);
    return len;
}

