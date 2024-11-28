#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args) {
    return write(1, &va_arg(args, int), 1);
}

int print_string(va_list args) {
    char *str = va_arg(args, char *);
    int count = 0;
    while (str && str[count]) {
        write(1, &str[count], 1);
        count++;
    }
    return count;
}

int _printf(const char *format, ...) {
    va_list args;
    int count = 0, i = 0;
    print_type types[] = {{"c", print_char}, {"s", print_string}, {NULL, NULL}};

    va_start(args, format);
    while (format && format[i]) {
        if (format[i] == '%') {
            i++;
            int j = 0;
            while (types[j].format) {
                if (types[j].format[0] == format[i]) {
                    count += types[j].func(args);
                    break;
                }
                j++;
            }
            if (!types[j].format) count += write(1, &format[i - 1], 2);
        } else {
            count += write(1, &format[i], 1);
        }
        i++;
    }
    va_end(args);
    return count;
}
