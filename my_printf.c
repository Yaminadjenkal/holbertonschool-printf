#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include "main.h"

int append_to_buffer(char *buffer, int *p_buffer_index, char c) {
    buffer[(*p_buffer_index)++] = c;
    return 1;
}

int format_number(unsigned int num, char *buffer, int *p_buffer_index, int base, int is_negative) {
    char str[11];
    int i = -1;
    int char_count = 0;

    if (is_negative) {
        append_to_buffer(buffer, p_buffer_index, '-');
        char_count++;
    }

    if (num == 0) {
        append_to_buffer(buffer, p_buffer_index, '0');
        return char_count + 1;
    }

    while (num > 0) {
        int digit = num % base;
        str[++i] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
        num /= base;
    }

    char_count += i;

    while (i >= 0) {
        append_to_buffer(buffer, p_buffer_index, str[i--]);
    }

    return char_count;
}

int format_hex(uintptr_t num, char *buffer, int *p_buffer_index) {
    char str[17];
    int i = -1;
    int char_count = 0;

    if (num == 0) {
        append_to_buffer(buffer, p_buffer_index, '0');
        return char_count + 1;
    }

    while (num > 0) {
        int digit = num % 16;
        str[++i] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
        num /= 16;
    }

    char_count += i;

    while (i >= 0) {
        append_to_buffer(buffer, p_buffer_index, str[i--]);
    }

    return char_count;
}

int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[1024];
    int buffer_index = 0;
    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                case 'i':
                    count += format_number(va_arg(args, int), buffer, &buffer_index, 10, va_arg(args, int) < 0);
                    break;
                case 'u':
                    count += format_number(va_arg(args, unsigned int), buffer, &buffer_index, 10, 0);
                    break;
                case 'o':
                    count += format_number(va_arg(args, unsigned int), buffer, &buffer_index, 8, 0);
                    break;
                case 'x':
                case 'X':
                    count += format_number(va_arg(args, unsigned int), buffer, &buffer_index, 16, 0);
                    break;
                case 'c':
                    count += append_to_buffer(buffer, &buffer_index, (char)va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str) {
                        append_to_buffer(buffer, &buffer_index, *str++);
                        count++;
                    }
                    break;
                }
                case 'p':
                    append_to_buffer(buffer, &buffer_index, '0');
                    append_to_buffer(buffer, &buffer_index, 'x');
                    count += format_hex((uintptr_t)va_arg(args, void *), buffer, &buffer_index);
                    break;
                case '%':
                    count += append_to_buffer(buffer, &buffer_index, '%');
                    break;
                default:
                    append_to_buffer(buffer, &buffer_index, '%');
                    append_to_buffer(buffer, &buffer_index, *format);
                    count += 2;
                    break;
            }
        } else {
            append_to_buffer(buffer, &buffer_index, *format);
            count++;
        }
        format++;
    }

    va_end(args);
    buffer[buffer_index] = '\0';
    printf("%s", buffer);
    return count;
}

int main() {
    my_printf("Let's try to printf a simple sentence.\n");
    my_printf("Length:[%d, %i]\n", 39, 39);
    my_printf("Negative:[%d]\n", -762534);
    my_printf("Unsigned:[%u]\n", 2147484671);
    my_printf("Unsigned octal:[%o]\n", 20000001777);
    my_printf("Unsigned hexadecimal:[%x, %X]\n", 0x800003ff, 0x800003FF);
    my_printf("Character:[%c]\n", 'H');
    my_printf("String:[%s]\n", "I am a string !");
    my_printf("Address:[%p]\n", (void*)0x7ffe637541f0);
    my_printf("Percent:[%%]\n");
    my_printf("Len:[%d]\n", 12);
    my_printf("Unknown:[%r]\n");
    return 0;
}

