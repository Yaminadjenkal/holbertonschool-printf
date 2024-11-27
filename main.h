#ifndef MAIN_H
#define MAIN_H

/**
 * _printf - Custom implementation of the printf function for formatted output.
 * @format: A null-terminated string that specifies the format of the output.
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...);

/**
 * _printf_modulo - Custom implementation for printing modulos.
 * @format: A null-terminated string that specifies the format of the output.
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf_modulo(const char *format, ...);

#endif /* MAIN_H */

