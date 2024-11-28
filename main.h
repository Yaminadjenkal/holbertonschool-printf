#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print_type - structure to map format specifiers to corresponding functions
 * @format: The format specifier (e.g. "c", "s")
 * @func: The function to call when the specifier is found
 */
typedef struct print_type
{
    char *format;
    int (*func)(va_list args);
} print_type;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);

#endif /* MAIN_H */

