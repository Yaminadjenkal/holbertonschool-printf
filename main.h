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
int append_to_buffer(char *buffer, int *p_buffer_index, char c);
int format_number(unsigned int num, char *buffer, int *p_buffer_index, int base, int is_negative);
int format_hex(uintptr_t num, char *buffer, int *p_buffer_index);
int my_printf(const char *format, ...);
#endif /* MAIN_H */
