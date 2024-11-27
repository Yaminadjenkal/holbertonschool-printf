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

/*
 * print_d - Function to handle the %d specifier.
 * @args: A va_list containing the integer to print.
 * Return: The number of characters printed.
 */
int print_d(va_list args);

#endif /* MAIN_H */

