#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _printf_modulo(const char *format, ...);
int print_d(va_list args);
void convert_to_string(int num, char *buffer, int len);
int calculate_length(int num);
int handle_negative(int num, char *buffer, int *len);
int print_i(va_list args);

#endif /* MAIN_H */
