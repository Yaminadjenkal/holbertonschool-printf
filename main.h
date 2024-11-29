#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct print_type
{
    char *format;
    int (*func)(va_list);
} print_type;

int _printf(const char *format, ...);
int handle_negative(int num, char *buffer, int *len);
int calculate_length(int num);
void convert_to_string(int num, char *buffer, int len);
int print_d(va_list args);
int print_i(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_modulo(va_list args);
int (*get_format_function(char c2))(va_list);
int print_reverse(va_list args);
#endif /* MAIN_H */
