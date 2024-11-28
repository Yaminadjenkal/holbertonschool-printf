#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct print_type
{
    char *format;
    int (*func)(va_list);
} print_type;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */
