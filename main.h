#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

typedef struct print_type
{
    char *format;
    int (*func)(va_list);
} print_type;

int print_char(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_string(va_list args);

#endif
