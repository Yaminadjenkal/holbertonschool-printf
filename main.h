#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdint.h>

int handle_negative(int num, char *buffer, int *len);
int calculate_length(int num);
void convert_to_string(int num, char *buffer, int len);

int print_char(va_list args, char *buffer, int *buffer_index);
int print_string(va_list args, char *buffer, int *buffer_index);
int print_percent(char *buffer, int *buffer_index);
int _printf(const char *format, ...);

#endif /* MAIN_H */

