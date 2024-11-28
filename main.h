#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int handle_negative(int num, char *buffer, int *len);
int calculate_length(int num);
void convert_to_string(int num, char *buffer, int len);
int print_d(va_list args);
int print_i(va_list args);
void print_string(const char *str, int *count);
void print_invalid_format(char specifier, int *count);
int _printf_string(const char *format, ...);
#endif /* MAIN_H */

